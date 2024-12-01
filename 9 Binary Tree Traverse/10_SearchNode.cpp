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
bool isPresent(Node* root,int searchVal)
{
    if(root==NULL)
        return false;
    if(root->data==searchVal)
        return true;
    bool leftSide= isPresent(root->Left,searchVal);
    bool rightSide= isPresent(root->Right,searchVal);

    if(leftSide || rightSide)
        return true;
    else
        return false;
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
    bool check=isPresent(root,5);
    if(check)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}