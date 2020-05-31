#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> v;
int ret = 0;
int n,m;
priority_queue<int> mq;
priority_queue<int> pq;

void minus_queue_func(priority_queue <int> & mq)
{
    if(mq.empty())
        return ;
    
    while(!mq.empty())
    {
        ret += mq.top() * 2;
        
        for(int i = 0; i < m; i++)
        {
            if(!mq.empty())
            {
                mq.pop();
            }
            else
            {
                break;
            }
        }
        
    }
}
void plut_init(priority_queue<int> & pq)
{
    if(pq.empty())
        return ;
    
    ret += pq.top();
    for(int i = 0; i < m; i++)
    {
        if(!pq.empty())
        {
            pq.pop();
        }
    }
}

void minus_init(priority_queue<int> & mq)
{
    if(mq.empty())
        return ;
    
    ret += mq.top();
    for(int i = 0; i < m; i++)
    {
        if(!mq.empty())
        {
            mq.pop();
        }
    }
}

void plus_queue_func(priority_queue <int> & pq)
{
    if(pq.empty())
        return ;
    
    while(!pq.empty())
    {
        ret += pq.top() * 2;
        
        for(int i = 0; i < m; i++)
        {
            if(!pq.empty())
            {
                pq.pop();
            }
            else
            {
                break;
            }
        }
        
    }
    
}
int main()
{
    
    int t;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> t;
        if(t < 0)
            mq.push(-t);
        else
            pq.push(t);
    }

    if(mq.empty() && !pq.empty()) //minus 숫자는 없고 plus 숫자만 있을때
    {
        plut_init(pq);
        plus_queue_func(pq);
    }
    else if(!mq.empty() && pq.empty()) //plus 숫자는 없고 minus 숫자만 있을때
    {
        minus_init(mq);
        minus_queue_func(mq);
    }
    else if(!mq.empty() && !pq.empty() && ( mq.top() < pq.top()))
    {
        plut_init(pq);
        plus_queue_func(pq);
        minus_queue_func(mq);
    }
    else
    {
        minus_init(mq);
        minus_queue_func(mq);
        plus_queue_func(pq);
    }
    
    cout << ret << "\n";
}
