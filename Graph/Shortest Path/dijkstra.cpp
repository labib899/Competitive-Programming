#include<bits/stdc++.h>
using namespace std;

#define fastIO          ios::sync_with_stdio(0);cin.tie(0);
#define pb              push_back
#define ff              first
#define ss              second
#define PQ              priority_queue
typedef long long       ll;
typedef vector<ll>      vll;
typedef pair<ll,ll>     pll;


const ll inf=1e18;
vll dist,vis;
vector<vector<pll>> adj;
ll source=1;


void dijkstra()
{
    dist[source]=0;
    PQ<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,source}); // pushing {distance,node}
    while(pq.size())
    {
        ll d=pq.top().ff;
        ll node=pq.top().ss;
        pq.pop();
        if(vis[node]) continue;
        vis[node]=1;
        for(auto x:adj[node])
        {
            ll adjNode=x.ff, wt=x.ss;
            if(d+wt<dist[adjNode]) // relaxation
            {
                dist[adjNode]=d+wt;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
}

void solve()
{
    ll n,m; cin>>n>>m;
    dist.resize(n+2,inf);
    adj.resize(n+2);
    vis.resize(n+2);

    for(int i=1;i<=m;i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    dijkstra();
    // printing distance from source to every other node
    for(int j=1;j<=n;j++) cout<<dist[j]<<" ";
    cout<<endl;
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
