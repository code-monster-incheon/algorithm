// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/17684
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,int> m;
vector<int> ret;

vector<int> solution(string msg) {
    
    
    for(char i = 'A'; i <= 'Z'; i++)
    {
        string temp = "";
        temp += i;
        m.insert(make_pair(temp, i - 'A' + 1));
    }
    
    int cur = (int)m.size();
    
    for(int i = 0; i < (int)msg.size(); i++)
    {
        string temp = "";
        
        temp += msg[i];
        
        int len = 0;
        
        while(true)
        {
            if(!m.count(temp))
                break;
            len++;
            temp += msg[i + len];
            
        }
        
        ret.push_back(m[msg.substr(i, len)]);
        m.insert(make_pair(msg.substr(i, len + 1), ++cur));

        i += len -1;
    }
    return ret;
}
