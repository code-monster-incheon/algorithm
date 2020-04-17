#include<iostream>
#include<algorithm>
#include<string.h>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int t[10];

bool visit[10];
bool banVisit[10];
int ret;
vector<int> numberStr;
set<string> s;
set<string> s2;

bool compare_string(string one, vector<string> usr, vector<string> ban)
{
    bool ban_visit[10];
    int cnt = 0;
    for(int i = 0; i < one.size(); i++)
    {
        int temp = one[i] - '0';
        string ts = usr[temp];
        string bs = ban[i];
        
        if(ts.size() != bs.size())
        {
            return false;
        }
        
        for(int j = 0; j < ts.size(); j++)
        {
            if(ts[j] != ban[i][j])
            {
                if(ban[i][j] != '*')
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}

void dfs(int index, vector<string> user_id, vector<string> banned_id)
{
    if(index == (int)banned_id.size())
    {
        string fiStr = "";
        
        for(int j = 0; j < numberStr.size(); j++)
        {
            fiStr += to_string(numberStr[j]);
            
        }
        
        if(s.insert(fiStr).second)
        {
            if(compare_string(fiStr,user_id, banned_id))
            {
                sort(fiStr.begin(), fiStr.end());
                
                if(s2.insert(fiStr).second)
                {
                    ret++;
                }
            }
            
        }
        
        return ;
    }
    
    for(int i = 0; i < user_id.size(); i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            numberStr.push_back(i);
            dfs(index + 1, user_id, banned_id);
            numberStr.pop_back();
            visit[i] = false;
        }
        
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    dfs(0, user_id, banned_id);
    return ret;
}
