#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
int arr[N];
int tree[N];

void Build(int idx,int val,int sz)
{
    while(idx<=sz)
    {
        tree[idx]+=val;
        idx+= (idx & -idx);
    }
}
void Print(int tree[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<tree[i]<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        Build(i,arr[i],n);
    }
    Print(tree,n);
    return 0;
}