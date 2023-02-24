#include <bits/stdc++.h>
using namespace std;


#define endl                    "\n"
#define pb                      push_back
#define F                       first
#define S                       second
typedef vector<int>             vi;
typedef pair<int,int>           pii;


int main()
{
    int n,m; cin>>n>>m;
    vi vis(n+1,0);
    vector<pii> adj[n+1],MST;
    for(int i=1;i<=m;i++)
    {
        int a,b,w; cin>>a>>b>>w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
    pq.push({0,{0,-1}}); // pushing weight,node and parent node
    int cost=0;
    while(!pq.empty())
    {
        auto x=pq.top(); pq.pop();
        int w=x.F;
        int node=x.S.F, parent=x.S.S;
        if(!vis[node])
        {
            if(x.S.S!=-1) MST.pb({parent,node}); // add it to MST if not visited
            vis[node]=1;
            cost+=w;
            for(auto c:adj[node])
            {
                int a=c.F, wt=c.S;
                if(!vis[a]) pq.push({wt,{a,node}});
            }
        }
    }
    cout<<"Minimum spanning tree edges: "<<endl;
    for(auto x:MST) cout<<x.F<<" "<<x.S<<endl;
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

