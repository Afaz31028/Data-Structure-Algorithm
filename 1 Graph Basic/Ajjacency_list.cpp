#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    int a[n][n];
    memset(a,0,sizeof(false));
    
    vector<int>adj_list[n];

    while(e--)
    {
        int i,j;
        cin>>i>>j;
        i--,j--;   //for 0 base indexing
        adj_list[i].push_back(j);
        adj_list[j].push_back(i);

    }

    cout<<"Adjacency List:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" -> ";
        for(int val: adj_list[i])
        {
            cout<<val+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
