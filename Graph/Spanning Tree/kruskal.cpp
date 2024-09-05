#include<bits/stdc++.h>
using namespace std;

#define pb              push_back
#define mt              make_tuple
#define all(x)          x.begin(),x.end()
typedef vector<int>     vi;
typedef tuple<int,int,int> tiii;


class DisjointSet
{
    vi size,parent;
    
public:
    
    DisjointSet(int n) // constructor
    {
        size.resize(n+1,1); 
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int Find(int x)
    {
        if(x==parent[x]) return x;
        return parent[x]=Find(parent[x]); // path compression, O(4a)
    }
    
    void Union(int a,int b) // union by size, O(4a)
    {
        a=Find(a), b=Find(b);
        if(size[a]<size[b]) swap(a,b);
        size[a]+=size[b]; // connect the smaller to the larger component
        parent[b]=a;
    }
};



int main()
{
    int n,m; cin>>n>>m;
    vector<tiii> adj; // adjacency list by weight
    for(int i=1;i<=m;i++)
    {
        int a,b,w; cin>>a>>b>>w;
        adj.pb(mt(w,a,b));
        adj.pb(mt(w,b,a));
    }
    
    DisjointSet ds(n);
    sort(all(adj)); // sorting edges by their weight
    int cost=0;
    cout<<"Minimum spanning tree edges: "<<endl;
    for(auto x:adj)
    {
        int w=get<0>(x);
        int a=get<1>(x), b=get<2>(x);
        if(ds.Find(a)!=ds.Find(b))
        {
            cost+=w;
            ds.Union(a,b);
            cout<<a<<" "<<b<<endl;
        }
    }
    cout<<"Minimum cost: "<<cost<<endl;
}


/*
 9 14
 0 1 4
 0 7 8
 1 2 8
 1 7 11
 2 3 7
 2 8 2
 2 5 4
 3 4 9
 3 5 14
 4 5 10
 5 6 2
 6 7 1
 6 8 6
 7 8 7
*/
