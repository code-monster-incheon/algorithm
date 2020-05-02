//https://programmers.co.kr/learn/courses/30/lessons/17684
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    int index = 1;
    map<string, int> m;
    map<string, int>::iterator iter;
    
    for(char i = 'A'; i <= 'Z'; i++) {
        string str = "";
        str += i;
        m[str] = index++;
    }
    
    int mSize = msg.size();
    int findFlag = false;
    for(int i = 0; i < mSize; i++) {
        int cnt = 1;
        while(i + cnt != mSize + 1) {
            if(m.find(msg.substr(i, cnt)) == m.end()) {
                findFlag = true;
                break;
            }
            cnt++;
        }
        
        answer.push_back((*m.find(msg.substr(i, cnt - 1))).second);
        if(findFlag) {
            m[msg.substr(i, cnt)] = index++;
            i += (cnt - 2);
        }
    }
    
    
    return answer;
}