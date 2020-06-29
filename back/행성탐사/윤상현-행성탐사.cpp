#include <iostream>
#include <string.h>
#include<vector>
#include<algorithm>
using namespace std;

// n : 가로 , m : 세로
int n,m,k;
char op[1001][1001];
int y[1001][1001][3];
int a,b,c,d;
char type[3] = {'J', 'O', 'I'};

void sumOfMap()
{
    memset(y,0,sizeof(y));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for(int t = 0; t < 3; t++)
            {
                y[i][j][t] = y[i - 1][j][t] + y[i][j - 1][t] - y[i - 1][j - 1][t];
                
                if(op[i][j] == type[t])
                {
                    y[i][j][t]++;
                }
            }
        }
    }
    
}

int main()
{
    memset(op, 0, sizeof(op));
    
    cin >> m >> n >> k;
    
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >>str;
        
        for(int j = 0 ; j< str.size(); j++)
        {
            op[i+1][j+1] = str[j];
        }
    }
    
    
    sumOfMap();
    
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        scanf("%d", &d);
        
        
        
        
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", y[c][d][j] - y[c][b -1][j] - y[a - 1][d][j] + y[a - 1][b - 1][j]);
        }
        printf("\n");
        
    }
    
    
    
}
