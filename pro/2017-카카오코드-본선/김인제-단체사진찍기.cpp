#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

char friends1[8];
vector<char> perm;
vector<bool> visit;
int ret;

bool check(int offset, int dist, char op){
    if (op == '<'){
        return (dist < offset);
    }
    else if (op == '='){
        return (dist == offset);
    }
    else {
        return (dist > offset);
    }
}

void dfs(int count, int n, vector<string>& data){
    if (count == n){
        
        for (int k = 0; k < data.size(); k++){
            string command = data[k];

            char person1 = command[0];
            char person2 = command[2];
            char op = command[3];
            int offset = command[4] - '0';
            
            int a = 0, b = 0;
            
            for (int i = 0; i < 8; i++){
                if (::perm[i] == person1)
                    a = i;
                else if (::perm[i] == person2)
                    b = i;
            }
            
            int dist = abs(a - b) - 1;
            
            if (check(offset, dist, op) == false)
                return;
            
        }
        ret++;
        
        return;
    }
    
    for (int i = 0; i < n; i++){
        if (::visit[i])   continue;
        
        ::visit[i] = true;
        ::perm.push_back(friends1[i]);
        
        dfs(count+1, n, data);
        
        ::perm.pop_back();
        ::visit[i] =false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string temp = "ACFJMNRT";
    for(int i = 0; i < 8; i++){
        ::visit.push_back(false);
        ::friends1[i] = temp[i];
    }
    ::ret = 0;


    
    dfs(0, 8, data);
    return ::ret;
}