#include <bits/stdc++.h>
using namespace std;
vector<int>dis(10000);
class edge
{
    public:
        int a,b,cost;
        edge(int a,int b,int cost)
        {
            this->a=a;
            this->b=b;
            this->cost=cost;
        }
};
int main()
{
    int n,e;
    cin>>n>>e;
    vector<edge> edgelist;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edgelist.push_back(edge(a,b,c));
    }
    for(int i=1;i<=n;i++)
    {
        dis[i]=INT_MAX;
    }
    dis[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(edge ed: edgelist)
        {
            int u=ed.a;
            int v=ed.b;
            int cost=ed.cost;
            if(dis[u] <INT_MAX && dis[u]+cost < dis[v])
            {
                dis[v]=dis[u]+cost;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<dis[i]<<endl;
    }
    return 0;
}