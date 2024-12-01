#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int n,m;
int arr[20][20];
int vis[20][20];
//int dis[20][20];

bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    else
        return true;
}
void dfs(int i,int j)
{
    vis[i][j]=true;
    //dis[i][j]=0;
        for(int i=0;i<4;i++)
        {
           int x= i+ dx[i];
           int y= i+ dy[i];
           if(valid(x,y) && !vis[x][y])
           {
                dfs(x,y);
           }

        }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    memset(vis,false,sizeof(false));
    //memset(dis,-1,sizeof(false));

    int src_i,src_j;
    cin>>src_i>>src_j;
    dfs(src_i,src_j);
    return 0;
}