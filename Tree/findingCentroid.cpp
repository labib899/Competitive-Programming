#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> sub;

void dfs(int node,int p)
{   
    sub[node]=1;
    for(auto c:g[node])
    {
        if(c==p) continue; 
        dfs(c,node);
        sub[node]+=sub[c];
    }
}

// O(n)
int get_centroid(int node,int p,int sz)
{
    for(auto c:g[node])
    {
        if(c==p) continue;
        if(sub[c]>sz/2) return get_centroid(c,node,sz);
    }
    return node;
}

void solve()
{
    int n; cin>>n;
    g.resize(n+1);
    sub.resize(n+1);
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,-1);
    cout<<get_centroid(1,-1,n)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}