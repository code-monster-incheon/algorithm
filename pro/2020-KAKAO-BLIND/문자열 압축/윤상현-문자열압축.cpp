// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/60057
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> v[1001];

int solution(string s)
{
    if(s.size() == 1)
    {
        return 1;
    }
    
    for(int len = 1; len <= s.size() / 2; len++)
    {
        int j = 0;
        for(j = 0; j <= s.size() - len; j+= len)
        {
            v[len].push_back(s.substr(j, len));
        }
        
        if(j < s.size())
        {
            v[len].push_back(s.substr(j));
        }
        
    }
    
    int maxLen = 10000;
    
    for(int i = 1; i <= s.size()/2; i++)
    {
        string temp = "";
        
        int len =1;
        
        for(int j= 0; j<v[i].size()- 1; j++)
        {
            if(v[i][j] == v[i][j+1])
            {
                len++;
            }
            else
            {
                if(len != 1)
                {
                    string t = "";
                    t += to_string(len);
                    t += v[i][j];
                    temp += t;
                    len =1;
                }
                else
                {
                    temp += v[i][j];
                    len = 1;
                }
            }
        }
        
        if(len != 1)
        {
            string t = "";
            t += to_string(len);
            t += v[i][v[i].size()-1];
            temp += t;
        }
        else
        {
            temp += v[i][v[i].size()-1];
        }
        
        
        maxLen= min(maxLen, (int)temp.size());
        
    }
    
    return maxLen;
    
}