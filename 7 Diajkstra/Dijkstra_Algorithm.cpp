#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<pair<int,int>>arr[N];
vector<int>dis(N);

void dijkstra(int src)
{
    priority_queue<pair<int,int>>pq;
    pq.push({src,0});
    dis[src]=0;
    while(!pq.empty())
    {
        pair<int,int> par=pq.top();
        int node=par.first, cost=par.second;
        pq.pop();
        for(pair<int,int> child : arr[node])
        {
            int childNode=child.first;
            int childCost=child.second;
            if(cost+childCost<dis[childNode])
            {
                dis[childNode]=cost+childCost;
                pq.push({childNode,dis[childNode]});
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
        int a,b,val;
        cin>>a>>b>>val;
        arr[a].push_back({b,val});
        arr[b].push_back({a,val});

    }
    for(int i=0;i<=n;i++)
    {
        dis[i]=INT_MAX;
    }
    dijkstra(1);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<dis[i]<<endl;
    }
    return 0;
}