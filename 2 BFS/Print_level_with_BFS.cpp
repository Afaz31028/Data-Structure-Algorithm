#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
vector<int>arr[1005];
bool vis[1005]={false};
vector<int> level(1005,-1);

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    vis[node]=true;
    level[node]=1;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        cout<<par+1<<" "<<level[par]<<endl;
        for(int child: arr[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=true;
                level[child]=level[par]+1;
            }
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
        i--,j--;
        arr[i].push_back(j);
        arr[j].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            cout<<"New Figure:"<<endl;
            bfs(i);
        }
    }

    return 0;
}