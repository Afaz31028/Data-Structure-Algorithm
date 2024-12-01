#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
int arr[N];
int tree[N];
void Update(int idx,int val,int sz)
{
    while(idx<=sz)
    {
        tree[idx]+=val;
        idx+= (idx & -idx);
    }
}
long long Query(int idx)
{
    long long sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-= (idx & -idx);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        Update(i,arr[i],n);
    }
    while(q--)
    {
        int op;
        cin>>op;
        if(op==0)
        {
            int idx,val;
            cin>>idx>>val;
            Update(idx,val,n);
        }
        else
        {
            int idx;
            cin>>idx;
            long long ans= Query(idx);
            cout<<idx<<"->"<<ans<<endl;
        }
    }
    return 0;
}