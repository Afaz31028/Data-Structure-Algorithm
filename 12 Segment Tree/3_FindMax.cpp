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
    tree[node]=max(tree[left],tree[right]);
}
long long Query(int node,int beg,int end,int l,int r)
{
    if(beg>r || end<l)
        return INT_MIN;
    if(beg>=l && end<=r)
        return tree[node];
    int left=2*node,right=2*node+1, mid=(beg+end)/2;
    int q1=Query(left,beg,mid,l,r);
    int q2=Query(right,mid+1,end,l,r);
    return max(q1,q2);
}
void Update(int node,int beg,int end,int idx,int val)
{
    if(beg>idx || end<idx)
        return;
    if(beg>=idx && end<=idx)
    {
        tree[node]=val;
        return;
    }
    int left=2*node,right=2*node+1, mid=(beg+end)/2;
    Update(left,beg,mid,idx,val);
    Update(right,mid+1,end,idx,val);
    tree[node]=max(tree[left],tree[right]);
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
    long long sum=Query(1,1,n,2,5);
    cout<<"Before Upadting:"<<sum<<endl;
    Update(1,1,n,3,50);
    long long sum1=Query(1,1,n,2,5);
    cout<<"After updating:"<<sum1<<endl;

    return 0;
}