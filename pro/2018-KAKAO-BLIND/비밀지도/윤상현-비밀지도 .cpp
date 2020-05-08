//문제링크 :  https://programmers.co.kr/learn/courses/30/lessons/17681
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, string> m;
string convertNumber(int x, int len)
{
    if(m.count(x))
        return m[x];
    
    int copy = x;
    string temp = "";
    while(x > 0)
    {
        temp += to_string(x % 2);
        x /= 2;
    }
    
    int diff = len - (int)temp.size();
    
    for(int i = 0; i < diff; i++)
    {
        temp += "0";
    }
    
    reverse(temp.begin(), temp.end());
    m.insert(make_pair(copy, temp));
    
    return temp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
        
    vector<string> s1, s2;
    
    for(int i = 0; i < n; i++)
    {
        s1.push_back(convertNumber(arr1[i], n));
        s2.push_back(convertNumber(arr2[i], n));
    }
    
    for(int i = 0; i < n; i++)
    {
        string temp = "";
        
        for(int j = 0; j < s1[i].size(); j++)
        {
            if(s1[i][j] == '1' || s2[i][j] == '1')
            {
                temp += "#";
            }
            else
            {
                temp += " ";
            }
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}
