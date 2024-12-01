
//here src is a root node and N is another node
//I will see the path of going from Src to N
//suppose A(Src) -> B -> C -> D(N)

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
vector<int>arr[1005];
bool vis[1005]={false};
vector<int> level(1005,-1);
vector<int> par(1005,-1); // new add

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    vis[node]=true;
    level[node]=1;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        //cout<<p+1<<" "<<level[p]<<endl;
        for(int child: arr[p])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=true;
                level[child]=level[p]+1;
                par[child]=p;
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
        //i--,j--; //1 based node
        arr[i].push_back(j);
        arr[j].push_back(i);
    }
    
    bfs(3); //3 is src and root
    int des=5;
    stack<int>path; 
    //vectror<int>path;
    while(des!=-1)
    {
        path.push(des);
        des=par[des];
    }
    while(!path.empty())
    {
        cout<<path.top()<<" ";
        path.pop();

    }


    return 0;
}