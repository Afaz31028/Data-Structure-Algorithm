#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl '\n'
#define loop for (int i = 0; i < n; i++)
using namespace std;
const int N=1e5+5;
vector<int>arr[N];
vector<bool> vis(N,false);
vector<int> par(N,-1);

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    vis[node]=true;
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        for(int child: arr[parent])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=true;
                par[child]=parent;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    bfs(1);
    if(!vis[n])
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int des=n;
    vector<int>path;
    while(des!=-1)
    {
        path.push_back(des);
        des=par[des];
    }
    //path.push_back(1);
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(int val: path)
    {
        cout<<val<<" ";
    }
    return 0;
}