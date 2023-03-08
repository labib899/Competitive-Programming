#include<bits/stdc++.h>
using namespace std;


#define pb			        push_back
#define mt                  make_tuple
typedef vector<int>         vi;
typedef tuple<int,int,int>  tiii; 


int main()
{
	int n,m; cin>>n>>m;
	vector<tiii> adj;
	for(int i=1;i<=m;i++)
	{
		int a,b,w; cin>>a>>b>>w;
		adj.pb(mt(a,b,w));
        adj.pb(mt(b,a,w)); // for undirected graphs
	}
    vi distance(n+2,INT_MAX);
    int source; cin>>source;
    distance[source]=0;
    for(int i=1;i<=n-1;i++)
    {
        for(auto x:adj)
        {
            int a=get<0>(x),b=get<1>(x);
            int w=get<2>(x);
            distance[b]=min(distance[b],distance[a]+w);
        }
    }
    // Nth iteration to check negative cycle
    for(auto x:adj)
    {
        int a=get<0>(x),b=get<1>(x);
        int w=get<2>(x);
        if(distance[a]+w<distance[b])
        {
            cout<<"Negative Cycle"<<endl;
            return -1;
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