#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
const int A=26;

int trie[N][A];
bool endOfWord[N];
int nodeCount=1;

void initTrie()
{
    memset(trie,-1,sizeof(trie));
}

void insert(string word)
{
    int node=0;
    for(auto ch:word)
    {
        int idx=ch-'a';
        if(trie[node][idx]==-1) trie[node][idx]=nodeCount++;
        node=trie[node][idx];
    }
    endOfWord[node]=true;
}

bool search(string word)
{
    int node=0;
    for(auto ch:word)
    {
        int idx=ch-'a';
        if(trie[node][idx]==-1) return false;
        node=trie[node][idx];
    }
    return endOfWord[node];
}

bool startsWith(string prefix)
{
    int node=0;
    for(auto ch:prefix)
    {
        int idx=ch-'a';
        if(trie[node][idx]==-1) return false;
        node=trie[node][idx];
    }
    return true;
}

void solve()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        insert(s);
    }
    int q; cin>>q;
    while(q--)
    {   
        int type; cin>>type;
        string s; cin>>s;
        if(type==1) cout<<(search(s)==true ? "yes":"no")<<endl;
        else cout<<(startsWith(s)==true ? "yes":"no")<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    initTrie();
    int t=1; //cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}