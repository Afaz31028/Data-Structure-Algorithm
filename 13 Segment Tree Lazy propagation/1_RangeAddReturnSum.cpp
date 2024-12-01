#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
ll a[N],tree[4*N],lazy[4*N];
void push(int node,int b,int e)
{
    if(lazy[node]==0)
        return;
    tree[node]=(1LL*(e-b+1)*lazy[node]);
    if(b!=e)
    {
        int l=2*node, r=2*node+1;
        lazy[l]+=lazy[node];
        lazy[r]+=lazy[node];
    }
    lazy[node]=0;
}
void SegmentTree(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int mid=(b+e)/2, l=2*node, r=2*node+1;
    SegmentTree(l,b,mid);
    SegmentTree(r,mid+1,e);
    tree[node]= tree[l]+tree[r];
}
void Update(int node,int b,int e,int i,int j,int val)
{
    push(node,b,e);
    if(b>j || e<i)
        return;
    if(b>=i && e<=j)
    {
        lazy[node]=val;
        push(node,b,e);
        return;
    }
    int mid=(b+e)/2, l=2*node, r=2*node+1;
    Update(l,b,mid,i,j,val);
    Update(r,mid+1,e,i,j,val);
    tree[node]= tree[l]+tree[r];
}
ll Query(int node,int b,int e,int i,int j)
{
    push(node,b,e);
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int mid=(b+e)/2, l=2*node, r=2*node+1;
    ll q1=Query(l,b,mid,i,j);
    ll q2=Query(r,mid+1,e,i,j);
    return q1+q2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    SegmentTree(1,1,n);
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int u,v;
            cin>>u>>v;
            Update(1,1,n,u,u,v);
        }
        else
        {
            int i,j;
            cin>>i>>j;
            ll sum=Query(1,1,n,i,j);
            cout<<sum<<endl;
        }
    }
    
    return 0;
}