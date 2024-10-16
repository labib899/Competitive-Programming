#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n,m,timer=1;
vector<vector<int>> g;
vector<bool> vis;
vector<int> tin,low;
vector<pii> bridges;

void dfs(int node,int p)
{
    vis[node]=true;
    tin[node]=low[node]=timer++;
    for(auto c:g[node])
    {   
        if(c==p) continue;
        if(vis[c]==false)
        {
            dfs(c,node);
            low[node]=min(low[node],low[c]);
            if(low[c]>tin[node]) bridges.push_back({min(node,c),max(node,c)});
        }
        else low[node]=min(low[node],tin[c]);
    }
}

void clear_all()
{
    g.clear(); 
    vis.clear(); 
    tin.clear(); 
    low.clear(); 
    bridges.clear(); 
    timer=1;
}

void solve()
{   
    cin>>n>>m;
    g.resize(n+1); 
    vis.resize(n+1,false); 
    tin.resize(n+1); 
    low.resize(n+1);
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false) dfs(i,-1);
    }
    int sz=bridges.size();
    if(sz==0) 
    {
        cout<<"No bridges"<<endl;
        return;
    }
    sort(bridges.begin(),bridges.end());
    cout<<sz<<endl;
    for(auto x:bridges) cout<<x.first<<" "<<x.second<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1; cin>>t;
    for(int i=1;i<=t;i++)
    {   
        clear_all();
        cout<<"Case "<<i<<": ";
        solve();
    }
}