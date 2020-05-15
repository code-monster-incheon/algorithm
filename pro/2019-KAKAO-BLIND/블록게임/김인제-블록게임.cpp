/*
1.  BFS 로 블록을 탐색한다
2.  위에서 검은 블록을 떨어뜨리므로, 없앨 수 있는 블록의 형태는 이미 결정되어 있다
3.  없앨 수 있는 블록의 형태이면 검은 블록을 떨어뜨릴 칸이 비어있는지 확인한다
4.  마지막으로 검은 블록을 떨어뜨릴 칸 위로 모든 칸이 비어있는지 확인한다 (위에서 아래로 검은 블록을 떨어뜨리므로 그 경로는 비어있어야 한다)
*/



#include <string>
#include <vector>
#include <queue>
#include <set>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int col, row;
set<string> blocks;

string bfs(int x, int y, vector<vector<int>>& board) {
    string ret = "";
    
    bool visited[8][8];
    memset(visited, false, sizeof(visited));
    
    int centerX = 4, centerY = 4;
    
    queue<pair<int, int>> q;
    q.push ({x, y});
    visited[centerX][centerY] = true;
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        // cout << curx << cury << endl;
        
        ret += to_string(curx-x);
        ret += ",";
        ret += to_string(cury-y);
        ret += " ";
        
        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= row || ny >= col)
                continue;
            
            if (board[nx][ny] == 0 || board[nx][ny] != board[x][y] || visited[nx-x+centerX][ny-y+centerY])
                continue;
            
            q.push({nx, ny});
            visited[nx-x+centerX][ny-y+centerY] = true;
        }
    }
    return ret;
}

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
 
    return internal;
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    row = board.size();
    col = row;
    
    blocks.insert("0,0 1,0 1,1 1,2 ");
    blocks.insert("0,0 1,0 2,0 2,-1 ");
    blocks.insert("0,0 1,0 2,0 2,1 ");
    blocks.insert("0,0 1,0 1,-1 1,-2 ");
    blocks.insert("0,0 1,0 1,1 1,-1 ");
    
    for (int k = 0; k < 200; k++){
        int count = 0;
        
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (board[i][j] != 0) {
                    string block = bfs(i, j, board);
                    
                    
                    
                    if (blocks.find(block) != blocks.end()) // find
                    {
                        int startX = i, startY = j;
                        int w = 0, h = 0;
                        
                        vector<string> tokens = split(block, ' ');
                        vector<string> lastToken = split(tokens[tokens.size()-1], ',');
                        
                        int endX = atoi(lastToken[0].c_str()), endY = atoi(lastToken[1].c_str());
                        endX += startX, endY += startY;
                        
                        
                        if (endX - startX == 1 && endY - startY == -1)
                            startY -= 1, endY+=2, w = 2, h = 1;
                        else
                            h = endX - startX, w = endY - startY;
                        
                        
                        bool flag = false;
                        cout << startX << ", " << startY << ", "<<endX<< ", "<<endY << ", " << w << ", " << h << endl;
                        
                        vector<pair<int, int>> empty;
                        
                        for (int r = startX; h > 0 ? r <= endX: r >= endX; h > 0 ? r++ : r--){
                            for (int c = startY; w > 0 ? c <= endY : c >= endY; w > 0 ? c++ : c--){
                                // cout << r << ", "<<c << endl;
                                if (board[r][c] == 0){
                                    empty.push_back({r, c});
                                    // cout << r << ", " << c << endl;
                                }
                                    
                                
                                if (board[r][c] != 0 && board[r][c] != board[i][j]){
                                    flag = true;
                                }
                            }
                            
                        }
                        
                        if (!flag){

                            
                            bool _flag = false;
                            
                            for (auto point : empty){
                                int x = point.first;
                                int y = point.second;
                                
                                if (_flag)
                                    continue;

                                for (int r = 0; r < x; r++)
                                    if (board[r][y] != 0){
                                        _flag = true;
                                        break;
                                    }
                            }
                            
                            if (_flag)
                                continue;
                            
                            count += 1;
                            for (int r = startX; h > 0 ? r <= endX : r >= endX; h > 0 ? r++ : r--){
                                for (int c = startY; w > 0 ? c <= endY : c >= endY; w > 0 ? c++ : c--){
                                    board[r][c] = 0;
                                    
                                }
                            }
                                    
                        }    
                    }
                }  
            }
        }
        
        if (count == 0)
            return answer;
        else
            answer += count;
        
    }
    
    return answer;
}