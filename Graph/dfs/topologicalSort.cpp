#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> adj;
vector<bool> vis;
void dfs(int node,stack<int> &st);


int main() 
{
    int n,m; cin>>n>>m;
    adj.resize(n+1),vis.resize(n+1,false);
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].pb(b);
    }

    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]) dfs(i,st);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}


void dfs(int node,stack<int> &st)
{
    vis[node]=true;
    for(auto x:adj[node])
    {
        if(!vis[x]) dfs(x,st);
    }
    st.push(node);
}

/*
 6 8
 0 1
 0 2
 1 3
 1 5
 2 3
 2 5
 3 4
 5 4
 */
