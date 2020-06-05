// https://www.acmicpc.net/problem/3085
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int n;
char d[51][51];


void swap(int & y, int & x)
{
    char temp = y;
    y = x;
    x = temp;
}

int check()
{
    int len = 0;
    int maxLen = 0;
    
    for(int i = 0; i < n; i++)
    {
        len = 1;
        for(int j = 0; j < n - 1; j++)
        {
            if(d[i][j] == d[i][j+1])
            {
                len++;
            }
            else
            {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        maxLen = max(maxLen, len);
    }
    
    for(int i = 0; i < n; i++)
    {
        len = 1;
        for(int j = 0; j < n - 1; j++)
        {
            if(d[j][i] == d[j + 1][i])
            {
                len++;
            }
            else
            {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        maxLen = max(maxLen, len);
    }
    
    return maxLen;
}
int main()
{
    memset(d, 0, sizeof(d));
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> d[i][j];
        }
    }
    int maxValue = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j + 1 < n)
            {
                swap(d[i][j], d[i][j + 1]);
                maxValue = max(check(), maxValue);
                swap(d[i][j], d[i][j + 1]);
            }
            
            if(i + 1 < n)
            {
                swap(d[i][j], d[i + 1][j]);
                maxValue = max(check(), maxValue);
                swap(d[i][j], d[i + 1][j]);
            }
        }
    }
    
    cout << maxValue << "\n";
    
    
}
