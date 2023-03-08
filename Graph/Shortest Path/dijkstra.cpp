#include<bits/stdc++.h>
using namespace std;

#define PQ				priority_queue
#define pb				push_back
#define ff 				first
#define ss    			second
typedef vector<int>		vi;
typedef pair<int,int>	pii;


int main()
{
	int n,m; cin>>n>>m;
	vector<pii> adj[n+2];
	for(int i=1;i<=m;i++)
	{
		int a,b,w; cin>>a>>b>>w;
		adj[a].pb({b,w});
		adj[b].pb({a,w});
	}
	vi distance(n+2,INT_MAX);
	int source; cin>>source; 
	distance[source]=0;
	PQ<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,source}); // push {dis,node}
	while(pq.size())
	{	
		int d=pq.top().ff;
		int node=pq.top().ss; 
		pq.pop();
		for(auto x:adj[node])
		{
			int adjNode=x.ff,w=x.ss;
			if(d+w<distance[adjNode])
			{
				distance[adjNode]=d+w;
				pq.push({distance[adjNode],adjNode});
			}
		}
	}
	// printing solution
	for(int i=0;i<n;i++) cout<<distance[i]<<" ";
	cout<<endl;
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
*/