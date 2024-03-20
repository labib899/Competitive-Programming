#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> color,parent;
int cycle_start=-1,cycle_end;

bool dfs(int node)
{
    color[node]=1;
    for(auto c:g[node])
    {
        if(color[c]==0)
        {
            parent[c]=node;
            if(dfs(c)) return true;
        }
        else if(color[c]==1)
        {
            cycle_start=c,cycle_end=node;
            return true;
        }
    }
    color[node]=2;
    return false;
}

void solve()
{
    int n,m; cin>>n>>m;
    g.resize(n+1);
    color.resize(n+1,0);
    parent.resize(n+1,-1);
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
    }
    bool cycle=false;
    for(int i=1;i<=n;i++)
    {
        if(!color[i]) 
        {
            cycle |=dfs(i);
            if(cycle) break;
        }
    }
    if(cycle)
    {
        vector<int> path;
        path.push_back(cycle_start);
        int node=cycle_end;
        while(node!=cycle_start)
        {
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(cycle_start);
        cout<<path.size()<<endl;
        reverse(path.begin(),path.end());
        for(auto x:path) cout<<x<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}