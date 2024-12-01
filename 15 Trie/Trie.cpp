#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Trie
{
    public:
        Trie* child[26];
        bool isEnd;
    Trie()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
};
void Insert(Trie* root, string word)
{
    Trie* cur=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        if(cur->child[ch-'a']==NULL)
        {
            Trie* next=new Trie();
            cur->child[ch-'a']=next;
        }
        cur=cur->child[ch-'a'];
    }
    cur->isEnd=true;
}
bool Search(Trie* root,string key)
{
    Trie* cur=root;
    for(int i=0;i<key.size();i++)
    {
        char ch=key[i];
        if(cur->child[ch-'a']==NULL)
            return false;
        cur=cur->child[ch-'a'];
    }
    return cur->isEnd;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> list;
    for(int i=0;i<5;i++)
    {
        string s;
        cin>>s;
        list.push_back(s);
    }
    Trie* root=new Trie();
    for(string ss : list)
    {
        Insert(root,ss);
    }
    vector<string> query={"pen","no","call"};
    for(int i=0;i<3;i++)
    {
        if(Search(root,query[i]))
            cout<<"Found"<<endl;
        else
            cout<<"Not found!"<<endl;

    }

    
    return 0;
}