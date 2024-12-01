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
Node* Convert(int n,int a[], int l,int r)
{
    if(l>r)
        return NULL;
    int mid=(l+r)/2;
    Node* root=new Node(a[mid]);
    Node* leftNode=Convert(n,a,l,mid-1);
    Node* rightNode=Convert(n,a,mid+1,r);
    root->left=leftNode;
    root->right=rightNode;
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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    Node *root= Convert(n,a,0,n-1);
    levelOrder(root);
    return 0;
}