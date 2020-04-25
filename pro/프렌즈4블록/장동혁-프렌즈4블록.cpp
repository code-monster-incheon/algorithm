#include <iostream>
#include <string>
#include <vector>

using namespace std;
int cnt = 0;

bool isRec(const vector<string>& board, vector<vector<bool>>& check, int y, int x) {\
    if(board[y][x] == '0') return false;
    if(board[y][x] != board[y][x + 1]) return false;
    if(board[y][x] != board[y + 1][x]) return false;
    if(board[y][x] != board[y + 1][x + 1]) return false;
    check[y][x] = check[y][x + 1] = check[y + 1][x] = check[y + 1][x + 1] = true;
    return true;
}

bool getCnt(vector<string>& board) {
    vector<vector<bool>> check(board.size(), vector<bool>(board[0].size(), false));
    bool changeFlag = false;
    
    for(int i = 0; i < board.size() - 1; i++) {
        for(int j = 0; j < board[0].size() - 1; j++) {
            if(isRec(board, check, i, j)) changeFlag = true;
        }
    }
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(check[i][j]) {
                board[i][j] = '0';
                cnt++;
            }
        }
    }
    
    for(int j = 0; j < board[0].size(); j++) {
        int index = -1;
        bool flag = false;
        for(int i = board.size() - 1; i >= 0; i--) {
            if(!flag && board[i][j] == '0') {
                flag = true;
                index = i;
            }
            if(flag && board[i][j] != '0') {
                board[index--][j] = board[i][j];
                board[i][j] = '0';
            }
        }
    }
    
    // for(int i = 0; i < board.size(); i++) {
    //     for(int j = 0; j < board[0].size(); j++) {
    //         cout << board[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout <<"==============\n";
    
    return changeFlag;
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    

    while(true) {
        if(!getCnt(board)) break;
    };
    answer = cnt;
    
    return answer;
}