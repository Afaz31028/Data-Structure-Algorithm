#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node* Left;
        Node* Right;
    Node(int val)
    {
        data=val;
        Left=NULL;
        Right=NULL;
    }

};
int SearchLevel(Node* root,int val)
{
    queue<pair<Node*,int>> q;
    q.push({root,1});
    int ok=-1;
    while(!q.empty())
    {
        pair<Node*,int> par= q.front();
        q.pop();
        Node* parNode=par.first;
        int parLevel=par.second;
        if(parNode->data==val)
        {
            ok=parLevel;
            break;
        }
        if(parNode->Left)
            q.push({parNode->Left,parLevel+1});
        if(parNode->Right)
            q.push({parNode->Right,parLevel+1});
    
    }
    return ok;
    
}
Node* Input()
{
    int val;
    cin>>val;
    Node* node;
    if(val==-1)
    {
        node=NULL;
    }
    else
    {
        node=new Node(val);
    }
    queue<Node*> q;
    if(node!=NULL)
    {
        q.push(node);
    }
    while(!q.empty())
    {
        Node* par=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        Node* left;
        Node* right;
        if(l==-1)
            left=NULL;
        else
            left=new Node(l);
        if(r==-1)
            right=NULL;
        else
            right=new Node(r);
        
        par->Left=left;
        par->Right=right;

        if(par->Left!=NULL)
            q.push(left);
        if(par->Right!=NULL)
            q.push(right);
    }
    return node;

}
int main()
{
    Node* root=Input();
    int level=SearchLevel(root,4);
    cout<<level<<endl;
    return 0;
}