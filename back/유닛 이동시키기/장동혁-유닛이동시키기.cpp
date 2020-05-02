// https://www.acmicpc.net/problem/2194
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define endl '\n'


using namespace std;


struct Point {
    int y;
    int x;
    int dist;
    Point(int a, int b, int c) : y(a), x(b), dist(c) {}
};

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int N, M, A, B, K;

vector<vector<int>> map;
vector<vector<bool>> visited;


bool canGo(int my, int mx) {
    if(my < 0 || mx < 0 || my + A - 1 >= N || mx + B - 1 >= M) return false;
    for(int i = my; i < my + A; i++) {
        for(int j = mx; j < mx + B; j++) {
            if(map[i][j] == -1) return false;
        }
    }

    return true;
}


int bfs(int sy, int sx, int ey, int ex) {

    Point p(sy, sx, 0);
    queue<Point> q;
    q.push(p);
    visited[sy][sx] = true;



    while(!q.empty()) {
        Point curPoint = q.front();
        
        q.pop();
        int y = curPoint.y;
        int x = curPoint.x;
        int dist = curPoint.dist;
            
        if (y == ey && x == ex) {
            return dist;
        }

        for(int dir = 0; dir < 4; dir++){
            int my = y + dy[dir];
            int mx = x + dx[dir];
            if(canGo(my, mx) && !visited[my][mx]) {
                visited[my][mx] = true;
                q.push(Point(my, mx, dist + 1));
            }
        }
    }

    return -1;
    
}



int main() {
    cin >> N >> M >> A >> B >> K;
    map.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));

    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        map[a - 1][b - 1] = -1;
    }

    int sy, sx, ey, ex;
    cin >> sy >> sx >> ey >> ex;
    sy--; sx--; ey--; ex--;

    int res = bfs(sy, sx, ey, ex);

    if(res == INF) {
        cout << -1;
    } else {
        cout << res;
    }
    

    return 0;
}