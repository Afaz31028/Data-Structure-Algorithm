#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>arr[N];
vector<bool> vis(N,false);
vector<int> result;

void dfs(int node)
{
    vis[node]=true;
    for(int child: arr[node])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
    result.push_back(node);
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
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
            dfs(i);
    }
    reverse(result.begin(),result.end());
    for(int val: result)
    {
        cout<<val<<" ";
    }
    return 0;
}