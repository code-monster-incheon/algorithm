//문제 링크 : https://www.acmicpc.net/problem/2194
#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int n, m, a, b, k, sy, sx, fy, fx;


int dy[] = {0, 1, 0, -1}; // 서, 남, 동, 북 순으로 이동 함
int dx[] = {-1, 0, 1, 0};

int board[501][501];
bool visit[501][501];

int bfs(int y, int x)
{
    queue< pair< pair<int, int>, int> > q;
    
    q.push({{y, x}, 0});
    visit[y][x] = true;
    while(!q.empty())
    {
        int _y = q.front().first.first;
        int _x = q.front().first.second;
        
        int len = q.front().second;
        
        if(_y == fy && _x == fx)
        {
            return len;
        }
        
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            bool test = false;
            
            int ny = dy[i] + _y;
            int nx = dx[i] + _x;
            
            if(ny <= 0 || nx <= 0 || ny + a - 1 > n || nx + b - 1 > m || visit[ny][nx])
            {
                continue;
            }
            
            if(i == 0) // 서쪽 이동
            {
                for(int s = 0; s < a; s++)
                {
                    if(board[ny + s][nx] == 1)
                    {
                        test = true;
                        break;
                    }
                }
            }
            else if(i == 1) // 남쪽 이동
            {
                for(int g = 0; g < b; g++)
                {
                    if(board[ny + a - 1][nx + g] == 1)
                    {
                        test = true;
                        break;
                    }
                }
            }
            else if(i == 2) //동쪽 이동
            {
                for(int s = 0; s < a; s++)
                {
                    if(board[ny + s][nx + b - 1] == 1)
                    {
                        test = true;
                        break;
                    }
                }
            }
            else if(i == 3) //북쪽 이동
            {
                for(int g = 0; g < b; g++)
                {
                    if(board[ny][nx + g] == 1)
                    {
                        test = true;
                        break;
                    }
                }
            }
            
            if(!test)
            {
                visit[ny][nx] = true;
                q.push({{ny, nx}, len + 1});
            }
            
        }
    }
    
    return -1;
}


int main()
{
    
    cin >> n >> m >> a >> b >> k;
    
    memset(board, 0, sizeof(board));
    
    for(int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        board[y][x] = 1;
    }
    
    cin >> sy >> sx >> fy >> fx;
    
    cout << bfs(sy, sx) << "\n";
    
}
