//문제 링크 https://www.acmicpc.net/problem/2872

#include <iostream>

using namespace std;

int n;
int d[300001];

int main(int argc, const char * argv[]) {

    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    
    int num = n;
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(d[i] == num) num--;
    }
    
    cout << num << "\n";
    
}
