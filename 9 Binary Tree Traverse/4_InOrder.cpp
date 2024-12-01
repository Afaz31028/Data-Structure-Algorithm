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

void InOrder(Node* node)
{
    if(node==NULL)
        return;
    InOrder(node->left);
    cout<<node->data<<" ";
    InOrder(node->right);
    

}
int main()
{
    Node* root=new Node(1);
    Node* a=new Node(2);
    Node* b=new Node(3);
    Node* c=new Node(4);
    Node* d=new Node(5);
    Node* e=new Node(6);

    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;

    InOrder(root);
    
    return 0;
}