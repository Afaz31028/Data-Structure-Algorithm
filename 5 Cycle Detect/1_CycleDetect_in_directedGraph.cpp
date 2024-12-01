#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>arr[N];
vector<bool> vis(N,false);
vector<int> pathVis(N,false);
bool ok;
void dfs(int node)
{
    vis[node]=true;
    pathVis[node]=true;
    for(int child: arr[node])
    {
        if(pathVis[child]==true)
        {
            ok=true;
        }
        if(!vis[child])
        {
            dfs(child);
        }
    }
    pathVis[node]=false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
    }
    ok=false;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }

    if(ok)
    {
        cout<<"Cycle detected"<<endl;
    }
    else
    {
        cout<<"Cycle not found!"<<endl;
    }
    return 0;
}