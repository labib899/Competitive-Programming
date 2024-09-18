#include <bits/stdc++.h>
using namespace std;


#define ff                      first
#define ss                      second
#define PQ                      priority_queue
typedef pair<int,int>           pii;
typedef tuple<int,int,int>      tiii;


vector<int> vis;
vector<vector<pii>> adj;
vector<pii> MST;
int cost=0;

void prim()
{
    PQ<tiii,vector<tiii>,greater<tiii>> pq;
    pq.push(make_tuple(0,0,-1)); // pushing weight,node and parent node
    while(!pq.empty())
    {
        auto x=pq.top(); pq.pop();
        int w=get<0>(x);
        int node=get<1>(x), parent=get<2>(x);
        
        if(vis[node]) continue; // if visited don't proceed
        if(parent!=-1) MST.push_back({parent,node}); // add to MST if not visited
        vis[node]=1; 
        cost+=w; // add weight to the cost
        for(auto c:adj[node])
        {
            int a=c.ff, wt=c.ss;
            if(!vis[a]) pq.push(make_tuple(wt,a,node)); // if not visited, push in the pq
        }
    }
}

int main()
{
    int n,m; cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int a,b,w; cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    
    prim();
    cout<<"Minimum spanning tree edges: "<<endl;
    for(auto x:MST) cout<<x.ff<<" "<<x.ss<<endl;
    cout<<"Minimum cost: "<<cost<<endl;
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

