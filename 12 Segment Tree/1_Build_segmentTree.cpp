#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N];
int tree[4*N];
void Build(int node,int beg,int end)
{
    if(beg==end)
    {
        tree[node]=a[beg];
        return;
    }
    int mid=(beg+end)/2;
    int left=2*node;
    int right=2*node+1;
    Build(left,beg,mid);
    Build(right,mid+1,end);
    tree[node]=tree[left]+tree[right]; // For summation
}
void print(int n)
{
    for(int i=1;i<=(4*n);i++)
    {
        cout<<tree[i]<<" ";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    Build(1,1,n);
    print(n);

    return 0;
}