#include <bits/stdc++.h>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char arr[1000][1000];
bool vis[1000][1000];
int n,m;

bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    else
        return true;
}

void dfs(int ci,int cj)
{
    vis[ci][cj]=true;
    for(int i=0;i<4;i++)
    {
        int x= ci+dx[i];
        int y= cj+dy[i];
        if(valid(x,y) && !vis[x][y])
        {
            dfs(x,y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    memset(vis,false,sizeof(false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='#')
                vis[i][j]=true;
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j])
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt<<endl;


    return 0;
}