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
bool SearchNode(Node* root,int val)
{
    if(root==NULL)
        return false;
    if(root->data== val)
        return true;
    if(val < root->data)
    {
        // bool l=SearchNode(root->Left,val);
        // if(l)
        //     return true;
        // else
        //     return false;
        return SearchNode(root->Left,val);
    }
    else
    {
        // bool r=SearchNode(root->Right,val);
        // if(r)
        //     return true;
        // else
        //     return false;
        return SearchNode(root->Right,val);
    }
    
    
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
    if(SearchNode(root,15))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found!"<<endl;

    return 0;
}