/*
* https://programmers.co.kr/learn/courses/30/lessons/17679
* 구현, 시뮬레이션 위주의 문제
*
*/

#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;
bool isBomb = true;

bool check(int i, int j, vector<string>& board) {
    if (board[i][j] != '*' && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i+1][j+1])
        return true;
    return false;
}

vector<pair<int, int>> bomb(int m, int n, vector<string>& board) {
    
    vector<pair<int, int>> v;
    
    for (int i = 0; i < m - 1; i++){
        for (int j = 0; j < n - 1; j++) {
            
            bool isBomb = check(i, j, board);
            
            if (isBomb)
                v.push_back({i, j});
            
        }
    }
    
    return v;
}

int erase(vector<pair<int, int>>& v, int m, int n, vector<string> &board) {
    int count = 0;
    
    bool erased[31][31];
    
    // Don't forget to initialize local variable!
    memset(erased, false, sizeof(erased));
    
    for (int i = 0; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;
        
        
        erased[x][y] = true;
        erased[x+1][y] = true;
        erased[x][y+1] = true;
        erased[x+1][y+1] = true;
    }
    

    

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            if (erased[i][j]) {
                count++;
                board[i][j] = '*';
                
            }
        }
    } 

    
    for (int j = 0; j < n; j++){
        string s;
        for (int i = m - 1; i >= 0; i--) {
            if (board[i][j] != '*')
                s += board[i][j];
            
        }

        int idx = 0;
        cout << s << endl;
        for (int i = m - 1; i >= 0; i--) {
            
            if (idx < s.length())
                board[i][j] = s[idx++];
            else
                board[i][j] = '*';
            
        }
        
    }
    
    
    return count;
    
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true) {
        vector<pair<int, int>> v = bomb(m, n, board);
        
        if (v.empty())
            break;
        

        
        answer += erase(v, m, n, board);
    }
    
    
    return answer;
}