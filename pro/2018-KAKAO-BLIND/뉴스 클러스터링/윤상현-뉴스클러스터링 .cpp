#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<string> s1;
vector<string> s2;

map<string,int> m1;
map<string,int> m2;
set<string> set1;


int solution(string str1, string str2)
{
    int diff = 'a' - 'A';

    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] >= 'A' && str1[i] <= 'z')
        {
            if(str1[i] >= 'a')
            {
                str1[i] -= diff;
            }
        }
    }

    for(int i = 0; i < str2.size(); i++)
    {
        if(str2[i] >= 'A' && str2[i] <= 'z')
        {
            if(str2[i] >= 'a')
            {
                str2[i] -= diff;
            }
        }
    }


    for(int i = 0; i < str1.size() - 1; i++)
    {
        if(str1[i] <= 'Z' && str1[i] >= 'A' && str1[i+1] <= 'Z' && str1[i+1] >= 'A')
        {
            string temp = "";
            temp += str1[i];
            temp += str1[i+1];
            s1.push_back(temp);
        }
    }

    for(int i = 0; i < str2.size() - 1; i++)
    {
        if(str2[i] <= 'Z' && str2[i] >= 'A' && str2[i+1] <= 'Z' && str2[i+1] >= 'A')
        {
            string temp = "";
            temp += str2[i];
            temp += str2[i+1];
            s2.push_back(temp);
        }
    }
    
    if(s1.size() == 0 && s2.size() == 0)
    {
        return 65536;
    }
    
    for(int i = 0; i < s1.size(); i++)
    {
        if(m1.count(s1[i]))
        {
            m1[s1[i]] = m1[s1[i]] + 1;
        }
        else
        {
            m1[s1[i]] = 1;
        }
        
        if(!set1.count(s1[i]))
        {
            set1.insert(s1[i]);
        }
    }
    
    
    for(int i=0;i <s2.size(); i++)
    {
        if(m2.count(s2[i]))
        {
            m2[s2[i]] = m2[s2[i]] + 1;
        }
        else
        {
            m2[s2[i]] = 1;
        }
        
        if(!set1.count(s2[i]))
        {
            set1.insert(s2[i]);
        }
        
    }
   
    double gyo = 0;
    double hab = (int) set1.size();
    
    for(auto iter = set1.begin(); iter != set1.end(); iter++)
    {
        if(m1.count(*iter)&& m2.count(*iter)) //둘다 있는 경우에
        {
            if(m2[*iter] < m1[*iter])
            {
                gyo += m2[*iter];
                hab += m1[*iter] - 1;
            }
            else if(m2[*iter] == m1[*iter])
            {
                gyo += m1[*iter];
                hab += m1[*iter] - 1;
            }
            else
            {
                gyo += m1[*iter];
                hab += m2[*iter] - 1;
            }
        }
        else if(m2[*iter] >= 1 && m1[*iter] == 0)
        {
            hab += m2[*iter] - 1;
        }
        else if(m2[*iter] == 0 && m1[*iter] >= 1)
        {
            hab += m1[*iter] - 1;
        }
    }
    
    int answer;
    answer = (gyo / hab) * 65536;
    return answer;
}
