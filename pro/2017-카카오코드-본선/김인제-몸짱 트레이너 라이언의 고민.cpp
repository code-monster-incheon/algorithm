#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int board[11][11];

const int CUSTOMER = 2;
const int BLOCKED = 1;
const int EMPTY = 0;


bool fillBoard(int n, int maxCustomer, int offset, int start){
    memset(board, EMPTY, sizeof(board));
    int ret = 1;
    board[0][start] = CUSTOMER;

    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == 0 && j == start)   continue;
            
            int dist = i + abs(j - start);
            if (dist < offset && board[i][j] == EMPTY)
                board[i][j] = BLOCKED;
        }
    }
    
    
    while(true){       
        int x = -1, y = -1;
        
        for (int i = 0; i < n; i++){
            if (x != -1)
                break;
            
            for(int j = 0; j < n; j++){
                if (board[i][j] == EMPTY){
                    board[i][j] = CUSTOMER;
                    ret++;
                    x = i, y = j;
                    break;
                }
            }
        }
        
        if (x == -1){

            return ret >= maxCustomer;
        }
        
        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (i == x && j == y)   continue;
                
                int dist = abs(x - i) + abs(y - j);
                if (board[i][j] == EMPTY && dist < offset)
                    board[i][j] = BLOCKED;
            }
        }
        // cout << "offset : " << offset << ", result : " <<ret << endl;
        // for (int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << board[i][j] << " ";
        //     }cout << endl;
        // }cout << endl << endl;
    }
    
    return ret >= maxCustomer;
}

bool isPossible(int n, int maxCustomer, int offset){
    
    for (int i = 0; i < n; i++){
               
        if (fillBoard(n, maxCustomer, offset, i))
            return true;
    }
    return false;
    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
    vector<int> timestamp(1400, 0);
    
    for(auto& time : timetable){
        int start = time[0];
        int end = time[1];
        
        timestamp[start]++;
        timestamp[end+1]--;
    }
    
    int customer = 0;
    int maxCustomer = 0;
    for(int i = 0; i < 1400; i++){
        customer += timestamp[i];
        maxCustomer = max(maxCustomer, customer);
    }
    // cout << maxCustomer<<endl;
    
    if (maxCustomer <= 1)
        return 0;
    
    // N x N 정사각형에 maxCustomer 만큼의 손님을 i 간격으로 배치할 수 있는가?
    for(int i = 1; i < 20; i++){
        if(isPossible(n, maxCustomer, i) == false)
            return i - 1;
    }
    
    int answer = 0;
    return answer;
}