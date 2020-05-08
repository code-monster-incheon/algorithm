#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt = 0;
int solution(string dartResult)
{
    string temp = "";
    vector<int> vec;
    
    for(int i = 0; i < dartResult.size(); i++)
    {
        if(dartResult[i] <= '9' && dartResult[i] >= '0')
        {
            temp += dartResult[i];
        }
        else if(dartResult[i] == 'S')
        {
            int cur = stoi(temp.c_str());
            vec.push_back(cur);
            
            temp = "";
        }
        else if(dartResult[i] == 'D')
        {
            int cur = stoi(temp.c_str());
            cur *= cur;
            vec.push_back(cur);
            
            temp = "";
        }
        else if(dartResult[i] == 'T')
        {
            int cur = stoi(temp.c_str());
            cur = cur * cur * cur;
            
            vec.push_back(cur);
            
            temp = "";
        }
        else if(dartResult[i] == '*')
        {
    
            if(vec.size() <= 1)
            {
                vec[vec.size() - 1] *= 2;
            }
            else
            {
                vec[vec.size() - 1] = vec[vec.size() - 1] * 2;
                vec[vec.size() - 2] = vec[vec.size() - 2] * 2;
            }
        }
        else if(dartResult[i] == '#')
        {
            vec[vec.size() - 1] *= -1;
        }
       
    }
    
    for(int i = 0; i < vec.size(); i++)
    {
        cnt += vec[i];
    }
    return cnt;
}