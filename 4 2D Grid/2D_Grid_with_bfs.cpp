#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int n,m;
int arr[20][20];
int vis[20][20];
int dis[20][20];

bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    else
        return true;
}
void bfs(int i,int j)
{
    queue<pair<int,int>>q;
    q.push({i,j});
    vis[i][j]=true;
    dis[i][j]=0;
    while(!q.empty())
    {
        pair<int,int> par= q.front();
        int par_i=par.first,par_j=par.second;
        q.pop();
        cout<<par.first<<" "<<par.second<<endl;
        for(int i=0;i<4;i++)
        {
            int x= par_i + dx[i];
            int y= par_j + dy[i];
            if(valid(x,y) && !vis[x][y])
            {
                vis[x][y]=true;
                q.push({x,y});
                dis[x][y]=dis[par.first][par.second]+1;
            }

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
    memset(dis,-1,sizeof(false));

    int src_i,src_j;
    cin>>src_i>>src_j;
    bfs(src_i,src_j);
    return 0;
}