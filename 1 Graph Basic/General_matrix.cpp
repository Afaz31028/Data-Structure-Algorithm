#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>a[n]; //2D vector
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int val;
            cin>>val;
            a[i].push_back(val);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}