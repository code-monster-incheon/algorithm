#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Point{
public:
    int x = 0;
    int y = 0;
    Point(){};
    Point(int x, int y) :x(x), y(y){};
};
char map[101][101];
int row, col;
vector<Point> alpha[26];

bool canErase(vector<Point> &points){
    int curx = points[0].x;
    int cury = points[0].y;
    
    int nx = points[1].x;
    int ny = points[1].y;
    int a = curx, b = cury;
    bool flag = true;
    
    if (curx == nx){
        for (int i = min(cury, ny) + 1; i < max(cury, ny); i++)
            if (map[curx][i] != '.')
                flag = false;
        return flag;
    }
    else if (cury == ny){
        for (int i = curx+1; i < nx; i++)
            if (map[i][cury] != '.')
                flag = false;
        return flag;
    }
    else{
    
        for (int i = curx+1; i <= nx; i++)
            if (map[i][cury] != '.')
                flag = false;

        for (int i = min(cury, ny) + 1; i < max(cury, ny); i++)
            if (map[nx][i] != '.')
                flag = false;

        if(flag) return true;
        flag = true;

        for (int i = min(cury, ny) + 1; i < max(cury, ny); i++)
            if (map[curx][i] != '.')
                flag = false;

        for (int i = curx; i < nx; i++)
            if (map[i][ny] != '.')
                flag = false;


        if(flag) return true;
        return false;
    }
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    row = m, col = n;
    
    int total = 0;
    
    for (int i = 0; i < 26; i++)
        alpha[i].clear();
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            map[i][j] = '.';
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            map[i][j] = board[i][j];
            if (board[i][j] != '*' && board[i][j] != '.'){
                int cur = board[i][j] - 'A';
                alpha[cur].push_back(Point(i, j));
                total++;
            }
        }
    }
    
    total /= 2;
    
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            
            if (alpha[j].size() > 0){
                
                if (canErase(alpha[j])){
                                        
                    map[alpha[j][0].x][alpha[j][0].y] = '.';
                    map[alpha[j][1].x][alpha[j][1].y] = '.';
                    alpha[j].clear();
                    
                    
                    
                    // for (int i = 0; i < row; i++){
                    //     for (int j = 0; j < col; j++){
                    //         cout << map[i][j] << " ";
                    //     }cout << endl;
                    // }cout << endl << endl;
                    
                    answer += ('A' + j);
                    break;
                }
            }
        }
    }
    cout << total << endl;
    if (answer.length() != total)
        return "IMPOSSIBLE";
    return answer;
    
}