#include <bits/stdc++.h>
#define ll long long
using namespace std;
string text, pat;
const int N = 1e5;
vector<int> lps(N);
void ComputeLPS(string &pat, vector<int> &lps)
{
    int sz = pat.size();
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < sz)
    {
        if (pat[len] == pat[i])
        {
            lps[i] = len + 1;
            i++;
            len++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
bool kmpSearch(string &text, string &pat)
{
    int n=text.size();
    int m = pat.size();
    ComputeLPS(pat,lps);
    int i=0,j=0;
    while(i<n)
    {
        if(text[i]==pat[j])
        {
            i++,j++;
            if(j==m)
            {
                //j=lps[j-1];
                return true;
            }
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin,text);
    cin >> pat;
    if(kmpSearch(text,pat))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    for (int i = 0; i < pat.size(); i++)
        cout << lps[i] << " ";
    return 0;
}