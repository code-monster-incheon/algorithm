#define DIVIDE 1000000000
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
long long d[101][101];
long long a[101][101];

int main()
{
    int n;
    cin >> n;
    string ori1, ori2;
    string a,b,c,d;
    cin >> ori1 >> ori2;
    
    a = ori1;
    b = ori2;
    c = ori1;
    d = ori2;
    int cnt1 = 1; //맨 왼쪽을 바꾸어 두고 시작할때에
    a[0] = (a[0] == '0' ? '1' : '0');
    a[1] = (a[1] == '0' ? '1' : '0');
    for(int i = 0; i < a.size() -1; i++)
    {
    
        if(a[i] != b[i])
        {
            cnt1++;
            a[i] = (a[i] == '0' ? '1' : '0');
            a[i+1] = (a[i+1] == '0' ? '1' : '0');
            
            if(i != a.size() - 2)
            {
                a[i+2] = (a[i+2] == '0' ? '1' : '0');
            }
        }
    
    }
    
    int cnt2 = 0;
    for(int i = 0; i < a.size() -1; i++)
    {
    
        if(c[i] != d[i])
        {
            cnt2++;
            c[i] = (c[i] == '0' ? '1' : '0');
            c[i+1] = (c[i+1] == '0' ? '1' : '0');
            
            if(i != a.size() - 2)
            {
                c[i+2] = (c[i+2] == '0' ? '1' : '0');
            }
        }
    
    }
    
  
    if(a == b && c != b)
    {
        cout << cnt1 << "\n";
    }else if(a != b && c == b)
    {
        cout << cnt2 << "\n";
    }
    else if(a == b && c ==b)
    {
        cout << min(cnt1, cnt2) << "\n";
    }
    else
    {
        cout << -1 <<"\n";
    }
}
