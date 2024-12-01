#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>arr[N];
vector<bool>vis(N,false);
vector<int> parArr(N,-1);
bool flag;
void dfs(int node)
{
    vis[node]=true;
    for(int child: arr[node])
    {
        if(vis[child] && parArr[node] != child)
        {
            flag=true;
        }
        if(!vis[child])
        {
            parArr[child]=node;
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
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);

    }

    flag=false;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    if(flag)
    {
        cout<<"Cycle detected"<<endl;
    }
    else
    {
        cout<<"Cycle Not found!"<<endl;
    }
    return 0;
}