#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> subtree_sum,vis;

void dfs(int node)
{
    vis[node]=1; subtree_sum[node]+=node;
    for(auto c:g[node])
    {
        if(vis[c]==0) 
        {
            dfs(c);
            subtree_sum[node]+=subtree_sum[c];
        }
    }
}

void solve()
{
    int n; cin>>n;
    g.resize(n+1); subtree_sum.resize(n+1,0); vis.resize(n+1,0);
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++) cout<<subtree_sum[i]<<" ";
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}


/*
13
1 2
1 3
1 13
2 5
3 4
4 9
4 10
5 6
5 7
5 8
8 12
10 11
*/