#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char ma[21][21]={0};
int visit[26]={0};
int dy[4]={0,0,-1,1}; //동서남북 순서로
int dx[4]={1,-1,0,0};
int ans=0;
int R,C;
void dfs(int g,int s,int cnt)
{
    ans=max(cnt,ans);
    for(int i=0;i<4;i++)
    {
        int nx=dx[i]+g;
        int ny=dy[i]+s;
        
        if(nx<0 || ny<0 || nx>=C || ny>=R)
            continue;
        
        int v=(int)ma[ny][nx]-65;
        if(visit[v]==1)
        {
            continue;
        }
        visit[v]++;
        dfs(nx,ny,cnt+1);
        visit[v]--;
    }

}

int main()
{
  
    
    string v;
    scanf("%d %d",&R,&C);
    
    for(int i=0;i<R;i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>ma[i][j];
        }
    }
 
    visit[(int)ma[0][0]-65]=1;
    dfs(0,0,1);
    
    cout<<ans<<endl;
    
}
