#include <iostream>

#include <string.h>

using namespace std;

bool visit[21];

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string str;
    cin >> n;
    int k;
    for(int i = 0; i < n; i++)
    {
        cin >>str;
        
        if(str != "all" && str[0] != 'e')
        {
            cin >> k;
        }
        
        if (str == "add")
        {
            visit[k] = true;
        }
        else if (str[0] == 'r')
        {
            visit[k] = false;
        }
        else if (str[0] =='c')
        {
            if(visit[k])
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if (str[0] == 't')
        {
            if (visit[k])
            {
                visit[k] = false;
            }
            else
            {
                visit[k] = true;
            }
        }
        else if (str == "all")
        {
            memset(visit, true, sizeof(visit));
        }
        else if (str == "empty")
        {
            memset(visit, false, sizeof(visit));
        }
    }
}
