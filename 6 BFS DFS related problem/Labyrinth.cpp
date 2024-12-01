#include <bits/stdc++.h>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char arr[1000][1000];
bool vis[1000][1000];
int dis[1000][1000];
pair<int,int> par[1000][1000];
int n,m;
vector<char>v;
bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    else
        return true;
}
void bfs(int ci,int cj)
{
    queue<pair<int,int>>q;
    q.push({ci,cj});
    vis[ci][cj]=true;
    dis[ci][cj]=0;
    while(!q.empty())
    {
        pair<int,int> parent=q.front();
        q.pop();
        int xi=parent.first,xj=parent.second;
        for(int i=0;i<4;i++)
        {
            int x= xi+dx[i];
            int y= xj+dy[i];
            if(valid(x,y) && !vis[x][y])
            {
                q.push({x,y});
                vis[x][y]=true;
                dis[x][y]=dis[xi][xj]+1;
                par[x][y]={dx[i],dy[i]};
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    memset(vis,false,sizeof(false));
    memset(dis,0,sizeof(dis));
    int si,sj,ei,ej;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            par[i][j]={-1,-1};
            if(arr[i][j]=='#')
                vis[i][j]=true;
            if(arr[i][j]=='A')
            {
                si=i;
                sj=j;
            }
            if(arr[i][j]=='B')
            {
                ei=i;
                ej=j;
            }
        }
    }
    bfs(si,sj);
    if(!vis[ei][ej])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    vector<pair<int,int>>path;
    pair<int,int> ans={ei,ej};
    while(ans.first!=si || ans.second!=sj)
    {
        path.push_back({par[ans.first][ans.second]});
        ans.first= ans.first-path.back().first;
        ans.second=ans.second-path.back().second;
    }
    reverse(path.begin(),path.end());
    if(vis[ei][ej])
    {
        cout<<"YES"<<endl;
        cout<<dis[ei][ej]<<endl;
        for(pair<int,int> x: path)
        {
            if(x.first==0 && x.second==-1)
                cout<<"L";
            if(x.first==0 && x.second==1)
                cout<<"R";
            if(x.first==-1 && x.second==0)
                cout<<"U";
            if(x.first==1 && x.second==0)
                cout<<"D";
            path.pop_back();
        }
    }



    return 0;
}