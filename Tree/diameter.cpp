#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
int maxD=-1,maxNode;

void dfs(int node,int d) // node and distance
{
    vis[node]=1;
    if(d>maxD) maxD=d,maxNode=node;
    for(auto c:g[node])
    {
        if(vis[c]==0) dfs(c,d+1);
    }  
}

void solve()
{
    int n; cin>>n;
    g.resize(n+1); 
    vis.resize(n+1,0);
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    maxD=-1;
    dfs(1,0);
    maxD=-1;
    for(int i=0;i<=n;i++) vis[i]=0;
    dfs(maxNode,0);
    cout<<maxD<<endl;
}

signed main()
{
    solve();
}