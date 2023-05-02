#include<bits/stdc++.h>
using namespace std;

#define fastIO              ios::sync_with_stdio(0);cin.tie(0);
#define pb                  push_back
#define mt                  make_tuple
#define ff                  first
#define ss                  second
#define all(x)              x.begin(),x.end()
#define PQ                  priority_queue
typedef long long           ll;
typedef vector<ll>          vll;
typedef pair<ll,ll>         pll;
typedef tuple<ll,ll,ll>     tlll;

const ll inf=1e18;
vector<vector<pll>> adj;
vector<pll> MST;
vll vis;

void prim(ll n) // O(E+VlogV), faster for dense graphs compared to Kruskal
{
    PQ<tlll,vector<tlll>,greater<tlll>> pq;
    pq.push(mt(0,0,-1)); // pushing {distance,node,parent}
    ll cost=0;
    while(pq.size())
    {
        auto x=pq.top(); pq.pop();
        ll w=get<0>(x);
        ll node=get<1>(x), parent=get<2>(x);
        if(vis[node]) continue;
        vis[node]=1;
        if(parent!=-1) MST.pb({parent,node}); // add edge to MST
        cost+=w;
        for(auto c:adj[node])
        {
            ll a=c.ff, wt=c.ss;
            if(!vis[a]) pq.push(mt(wt,a,node));
        }
    }

    cout<<"Minimum Spanning Tree Edges:"<<endl;
    for(auto x:MST) cout<<x.ff<<" "<<x.ss<<endl;
    cout<<"Minimum Cost: "<<cost<<endl;
}

void solve()
{
    ll n,m; cin>>n>>m;
    adj.resize(n+2);
    vis.resize(n+2,0);
    for(int i=1;i<=m;i++)
    {
        ll a,b,w; cin>>a>>b>>w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }

    prim(n);
}


int main()
{
    fastIO;
    int t=1; //cin>>t;
    while(t--)
    {
        solve();
    }
}


/*
 5 7
 0 1 2
 0 3 6
 1 2 3
 1 3 8
 1 4 5
 2 4 7
 3 4 9
*/
