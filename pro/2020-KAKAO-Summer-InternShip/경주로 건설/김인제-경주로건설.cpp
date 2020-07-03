/*
https://programmers.co.kr/learn/courses/30/lessons/67259

다익스트라 최단경로를 살짝 변형한 문제
일반적인 최단경로 문제와 달리, 직선 코스와 코너 코스로 이동이 가능
따라서, 직선 코스로 현재 칸에 도착한 경우와 코너 코스로 현재 칸에 도착한 경우를 나눠줘야 함
이때, 나누는 기준은 현재 칸에 도착하기 바로 직전에 이동한 방향

따라서, int dist[x][y][direction] 으로 (x, y) 까지의 최단 경로 배열을 선언해주고 다익스트라 돌려서 해결
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dist[26][26][4];    // dist[x][y][direction]
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int row, col;
const int INF = 987654321;

// 현재 좌표의 최단 경로 클래스
struct Point{
    int x;
    int y;
    int cost;
    int prevDirection;
    Point(int x, int y, int cost, int prevD)
        :x(x), y(y), cost(cost), prevDirection(prevD){};
};

// 최소 힙을 위한 비교 연산자
struct cmp{
    bool operator () (Point& a, Point& b){
        return a.cost > b.cost;
    }
};

int solution(vector<vector<int>> board) {
    int answer = INF;
    row = board.size();
    col = board[0].size();
    
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            for(int k = 0; k < 4; k++)
                dist[i][j][k] = INF;
    
    // 최소 힙
    priority_queue< Point, vector<Point>, cmp > pq;

    // dist[x][y][direction]
    dist[0][0][0] = 0;
    dist[0][0][1] = 0;
    dist[0][0][2] = 0;
    dist[0][0][3] = 0;
    
    // Point(x, y, cost, direction)
    pq.push(Point(0, 0, 0, 0));
    pq.push(Point(0, 0, 0, 1));
    pq.push(Point(0, 0, 0, 2));
    pq.push(Point(0, 0, 0, 3));
    
    // 다익스트라 최단 경로
    while(pq.empty() == false){
        Point cur = pq.top();
        int x = cur.x;
        int y = cur.y;
        int cost = cur.cost;
        int prevD = cur.prevDirection;
        
        pq.pop();
        
        // 인접한 칸으로 이동
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 이전에 왔던 칸으로 되돌아 가는 경우
            if ( abs(prevD - i) == 2)
                continue;
            
            // out of range
            if (nx < 0 || ny < 0 || nx >= row || ny >= col || board[nx][ny] == 1)
                continue;
            
            int _cost = 0;
            
            // 직진 코스 인 경우
            if ( prevD == i)
                _cost = 100;

            // 커브 코스인 경우, 500 원 추가
            else
                _cost = 600;
            
            // 다익스트라 최단경로의 정의
            int nextCost = cost + _cost;
            
            if (dist[nx][ny][i] > nextCost){
                dist[nx][ny][i] = nextCost;
                pq.push(Point(nx, ny, nextCost, i));
            }
        }
        
    }
    
    for(int k = 0; k < 4; k++)
        answer = min(answer, dist[row-1][col-1][k]);
    
    return answer;
}