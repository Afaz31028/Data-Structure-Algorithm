#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

};
Node* inputTree()
{
    int val;
    cin>>val;
    Node* root;
    if(val==-1)
    {
        root=NULL;
    }
    else
    {
        root=new Node(val);
    }
    queue<Node*>q;
    if(root!=NULL)
        q.push(root);
    while(!q.empty())
    {
        Node* f=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        Node* Left;
        Node* Right;
        if(l==-1)
        {
            Left=NULL;
        }
        else
            Left=new Node(l);
        if(r==-1)
        {
            Right=NULL;
        }
        else
            Right=new Node(r);
        f->left=Left;
        f->right=Right;

        if(f->left != NULL)
            q.push(f->left);
        if(f->right != NULL)
            q.push(f->right);
    }
    return root;
}
void levelOrder(Node* root)
{
    queue<Node*>q;
    if(root==NULL)
    {
        cout<<"tree nai"<<endl;
        return;
    }
    q.push(root);
    while(!q.empty())
    {
        Node* f=q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left != NULL)
            q.push(f->left);
        if(f->right != NULL)
            q.push(f->right);
    }
}
int main()
{
    Node* root =inputTree();
    levelOrder(root);
    return 0;
}