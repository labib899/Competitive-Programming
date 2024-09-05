#include<bits/stdc++.h>
using namespace std;

#define PQ				priority_queue
#define pb				push_back
#define ff 				first
#define ss    			second
#define all(x)			x.begin(),x.end()
#define inf				1e18
typedef long long		ll;
typedef vector<ll>		vll;
typedef pair<ll,ll>		pll;

vector<vector<pll>> adj;
vll dist,parent;

void dijkstra(ll source,ll dest)
{
	dist[source]=0;
	parent[source]=-1;
	PQ<pll,vector<pll>,greater<pll>> pq;
	pq.push({0,source}); // push {distance,node}
	while(pq.size())
	{	
		ll d=pq.top().ff;
		ll node=pq.top().ss; 
		pq.pop();
		for(auto x:adj[node])
		{
			ll adjNode=x.ff,w=x.ss;
			if(d+w<dist[adjNode])
			{
				dist[adjNode]=d+w;
				pq.push({dist[adjNode],adjNode});
				parent[adjNode]=node;
			}
		}
	}
}


int main()
{
	ll n,m; cin>>n>>m;
	adj.resize(n+2);
	dist.resize(n+2,inf);
	parent.resize(n+2,0);
	for(int i=1;i<=m;i++)
	{
		ll a,b,w; cin>>a>>b>>w;
		adj[a].pb({b,w});
		adj[b].pb({a,w});
	}

	ll source,dest; cin>>source>>dest; 
	dijkstra(source,dest);
	
	if(dist[dest]==inf) cout<<-1<<endl; // No path
	else
	{
		// path printing
		vll path;
		ll node=dest;
		while(node!=-1)
		{
			path.pb(node);
			node=parent[node];
		}
		reverse(all(path));
		for(auto x: path) cout<<x<<" ";
		cout<<endl;
	}
}


/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0 4
*/