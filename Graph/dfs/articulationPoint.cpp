#include <bits/stdc++.h>
using namespace std;

int n,m,timer=1;
vector<vector<int>> g;
vector<bool> vis;
vector<int> tin,low;
map<int,int> mp;

void dfs(int node,int p)
{
    vis[node]=true;
    tin[node]=low[node]=timer++;
    int child=0;
    for(auto c:g[node])
    {
        if(c==p) continue;
        if(vis[c]==false)
        {   
            dfs(c,node);
            low[node]=min(low[node],low[c]);
            if(low[c]>=tin[node] and p!=-1) mp[node]=1;
            child++;
        }
        else low[node]=min(low[node],tin[c]);
    }
    if(child>1 and p==-1) mp[node]=1;
}

void clear_all()
{
    g.clear(); 
    vis.clear(); 
    tin.clear(); 
    low.clear(); 
    mp.clear();
    timer=1;
}

void solve()
{
    cin>>n>>m;
    clear_all();
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
    cout<<mp.size()<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1; //cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}
