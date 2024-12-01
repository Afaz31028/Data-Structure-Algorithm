#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    // here n=number of nodes and e=number of edges

    int a[n][n];
    memset(a, 0, sizeof(a));
    while(e--)
    {
        int i,j;
        cin>>i>>j; //here i & j are index numbers
        a[i][j]=1; //undirected graph
        a[j][i]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}