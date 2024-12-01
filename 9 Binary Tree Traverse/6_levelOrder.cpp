#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* Left;
        Node* Right;
    Node(int data)
    {
        this->data=data;
        Left=NULL;
        Right=NULL;
    }
        
};
Node* InputBinTree()
{
    int val;
    cin>>val;
    Node* rootNode;
    if(val==-1)
        rootNode=NULL;
    else
        rootNode=new Node(val);
    queue<Node*>q;
    if(rootNode!=NULL)
        q.push(rootNode);
    while(!q.empty())
    {
        Node* parNode=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        Node* leftNode;
        Node* rightNode;
        if(l==-1)
            leftNode=NULL;
        else
            leftNode=new Node(l);
        if(r==-1)
            rightNode=NULL;
        else
            rightNode=new Node(r);

        parNode->Left=leftNode;
        parNode->Right=rightNode;

        if(leftNode!=NULL)
            q.push(leftNode);
        if(rightNode!=NULL)
            q.push(rightNode);
        
    }
    return rootNode;
    
}
void PrintLevelOrder(Node* src)
{
    queue<Node*>q;
    if(src==NULL)
    {
        cout<<"tree nai"<<endl;
        return;
    }
    q.push(src);
    while(!q.empty())
    {
        Node* par=q.front();
        q.pop();
        cout<<par->data<<" ";
        if(par->Left != NULL)
            q.push(par->Left);
        if(par->Right!=NULL)
            q.push(par->Right);
    }
}
int main()
{
    Node* root=InputBinTree();
    PrintLevelOrder(root);
    return 0;
}