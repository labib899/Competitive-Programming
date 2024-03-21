#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis,dist;
int maxD=-1,maxNode;

void dfs(int node,int d) 
{
    vis[node]=1;
    if(d>maxD) maxD=d,maxNode=node;
    for(auto c:g[node])
    {
        if(vis[c]==0) 
        {   
            dist[c]=d+1;
            dfs(c,d+1);
        }
    }  
}

void solve()
{
    int n; cin>>n;
    g.resize(n+1); 
    vis.resize(n+1);
    dist.resize(n+1);
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<=n;i++) vis[i]=0,dist[i]=0;
    maxD=-1;
    dfs(1,0);

    int point1=maxNode;
    for(int i=0;i<=n;i++) vis[i]=0,dist[i]=0;
    maxD=-1;
    dfs(point1,0);
    vector<int> dist1=dist;

    int point2=maxNode;
    for(int i=0;i<=n;i++) vis[i]=0,dist[i]=0;
    maxD=-1;
    dfs(point2,0);
    vector<int>dist2=dist;

    for(int i=1;i<=n;i++) cout<<max(dist1[i],dist2[i])<<" ";
    cout<<endl;
}

signed main()
{
    solve();
}