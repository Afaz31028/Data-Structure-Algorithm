#include<bits/stdc++.h>
using namespace std;
int n,e;
class Edge
{
    public:
        int u ,v, w;
        Edge(int u,int v, int w)
        {
            this->u=u;
            this->v=v;
            this->w=w;
        }
};
vector<Edge> result;
vector<int> tree_id(n+1);
vector<Edge> edges;

bool edgeComp (Edge a, Edge b) {
    return a.w < b.w;
}

int kruskals() {
    int cost = 0;
    for (int i = 1; i <= n; i++)
        tree_id[i] = i;

    sort(edges.begin(), edges.end(), edgeComp);

    for (Edge e : edges)
    {
        //cout<<e.u<<" "<<e.v<<" "<<e.w<<endl;
        if (tree_id[e.u] != tree_id[e.v])
        { 
            cost += e.w;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 1; i <=n; i++) {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }
    return cost;
}

int main()
{
    cin>>n>>e;
    while(e--) {
        int a,b,c;
        cin >> a>>b>>c;
        edges.push_back(Edge(a,b,c));
    }
    int val=kruskals();
    cout<<val<<endl;
    
    for(int i=0; i < n-1; i++)
    {
        cout << result[i].u << " " << result[i].v << " " << result[i].w << endl;
    }
}