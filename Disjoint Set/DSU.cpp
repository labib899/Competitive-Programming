#include <bits/stdc++.h>
using namespace std;

vector<int> parent,sz;

void make(int x) { parent[x]=x,sz[x]=1; }

int Find(int x)
{
    if(x==parent[x]) return x;
    return parent[x]=Find(parent[x]);  // path compression
}

void Union(int a,int b)  // union by size
{
    a=Find(a), b=Find(b);
    if(a!=b)
    {
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

void solve()
{
    int n,m; cin>>n>>m;
    parent.resize(n+1); sz.resize(n+1);
    for(int i=0;i<=n;i++) make(i);
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        Union(a,b);
    }
    int q; cin>>q;
    while(q--)
    {
        int a,b; cin>>a>>b;
        cout<<(Find(a)==Find(b) ? "YES":"NO")<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1; //cin>>t;
    while(t--) solve();
}



/*
 7 6
 1 2
 2 3
 4 5
 6 7
 5 6
 4 7
*/


/*
void Union(int a,int b)  // union by rank
{
    a=Find(a), b=Find(b);
    if(a!=b)
    {
        if(rank[a]<rank[b]) swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
    }
}
*/