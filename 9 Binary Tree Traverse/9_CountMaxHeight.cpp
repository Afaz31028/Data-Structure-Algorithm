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
            q.push(par->Left);
        if(par->Right!=NULL)
            q.push(par->Right);
    }
    return node;

}
int MaxHeight(Node* node)
{
    if(node==NULL)
        return 0;
    int l=MaxHeight(node->Left);
    int r=MaxHeight(node->Right);
    return max(l,r)+1;
}
int main()
{
    Node* root=Input();
    int num=MaxHeight(root);
    cout<<num<<endl;
    return 0;
}