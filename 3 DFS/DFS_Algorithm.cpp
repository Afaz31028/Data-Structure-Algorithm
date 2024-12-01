#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
vector<int> arr[1005];
vector<bool> vis(1005,false);

void dfs(int node)
{
    vis[node]=true;
    cout<<node<<" ";
    for(int child: arr[node])
    {
        if(vis[child]==false)
        {
            dfs(child);
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int i,j;
        cin>>i>>j;
        arr[i].push_back(j);
        arr[j].push_back(i);
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    
    return 0;
}