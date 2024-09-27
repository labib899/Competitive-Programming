#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> cnt,vis;

void dfs(int node)
{
    vis[node]=1; cnt[node]=1;
    for(auto c:g[node])
    {
        if(vis[c]==0) 
        {
            dfs(c);
            cnt[node]+=cnt[c];
        }
    }
}

void solve()
{
    int n; cin>>n;
    g.resize(n+1); cnt.resize(n+1,0); vis.resize(n+1,0);
    for(int i=2;i<=n;i++)
    {
        int x; cin>>x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}