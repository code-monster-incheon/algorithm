/*
https://programmers.co.kr/learn/courses/30/lessons/62050
최근 푼 문제 중 가장 좋았던 문제

1.  BFS 로 그룹 별로 분리
2.  그룹 정보를 기반으로 각 그룹의 사다리 연결 그래프 생성
    2-1.    이때 그룹의 최대 수 가 5000 개 이므로 2차원 배열로는 graoh[5000][5000] 이 필요하므로 메모리 부족
    2-2.    따라서 map 을 사용하여 하나의 그룹에 연결된 그룹들의 사다리 값 정보를 저장하거나
    2-3.    map 에 <here, there, cost> 처럼 그룹간 연결된 간선의 정보를 저장해야 함

3.  그룹간의 연결 정보를 기반으로 최소 신장 트리를 생성
    3-1.    크루스칼 이나 프림 알고리즘 모두 사용 가능, 그룹이 5000개 이므로 많지 않다

그룹 간 연결 정보를 그래프로 바꾸는 과정에서 어떤 자료구조로 저장할지가 중요했던 문제, 2차원 배열로는 해결 불가능
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int group[301][301];
vector<vector<int>> board;
int height, row, col;
int num_group = 0;

map<pair<int, int>, int> connectCost;


void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    group[x][y] = num_group;
    
    while(q.empty() == false){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            
            if (nx < 0 || ny < 0|| nx>=row || ny>=col||group[nx][ny] != -1)
                continue;
            
            int cost = abs(board[curx][cury] - board[nx][ny]);
            
            if (cost <= height){
                group[nx][ny] = num_group;
                q.push({nx, ny});
            }
        }
    }
}

void connect_group(){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            
            // Check Right, Down
            for(int k = 0; k < 2; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                            
                if (nx < 0 || ny < 0|| nx>=row || ny>=col)
                    continue;
                
                if (group[i][j] != group[nx][ny]){
                    int cost = abs(board[i][j] - board[nx][ny]);
                    int here = group[i][j];
                    int there = group[nx][ny];
                    
                    auto it = connectCost.insert({{here, there}, cost});
                    
                    if (it.second == false){
                        it.first->second = min (it.first->second, cost);
                        int _min = it.first->second;
                        it = connectCost.insert({{there, here}, _min});
                        
                        if (it.second == false)
                            it.first->second = _min;
                    }
                    else{
                        connectCost.insert({{there, here}, cost});
                    }
                    
                }
                
            }
        }
    }
    
    
}

int find(int x, vector<int>& parent){
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x], parent);
}

bool merge(int x, int y, vector<int>& parent, vector<int>& rank){
    x = find(x, parent);
    y = find(y, parent);
    
    if (x == y) return false;
    
    if (rank[x] > rank[y]){
        int temp = x;
        x = y;
        y = temp;
    }
    parent[x] = y;
    
    if (rank[x] == rank[y])
        rank[y]++;
    
    return true;
}

int MST(){
    vector<int> parent(num_group + 1);
    vector<int> rank (num_group + 1);
    
    
    for(int i = 0; i < num_group + 1; i++){
        parent[i] = i;
        rank[i] = 1;
    }
    
    priority_queue< pair<int, pair<int, int>> , vector<pair<int, pair<int, int>> >>  pq;
    
    for(auto iter = connectCost.begin(); iter != connectCost.end(); iter++){
        int cost = iter->second;
        int here = iter->first.first;
        int there = iter->first.second;
        
        //cout << here << "-" << there<<", cost: "<< cost << endl;
        
        pq.push({-cost, {here, there}});
    }
    
    int ret = 0;
    int count = 0;
    
    while(pq.empty() == false){
        int cost = -pq.top().first;
        int here = pq.top().second.first;
        int there = pq.top().second.second;
        pq.pop();
        
        if (merge(here, there, parent, rank)){
            ret += cost;
            count++;
            
            
            if (count == num_group - 1)
                break;
        }
        
    }
    
    return ret;

}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    board = land;
    ::height = height;
    row = land.size();
    col = land[0].size();
    memset(group, -1, sizeof(group));
    
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (group[i][j] == -1){
                num_group++;
                bfs(i, j);
            }
        }
    }
    
    // for (int i = 0; i < row; i++){
    //     for (int j = 0; j < col; j++){
    //         cout << group[i][j] << " ";
    //     }cout << endl;
    // }cout << endl << endl;
    
    connect_group();
    answer = MST();
    
    return answer;
}