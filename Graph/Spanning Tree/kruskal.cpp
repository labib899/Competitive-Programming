#include<bits/stdc++.h>
using namespace std;

#define pb              push_back
#define F               first
#define S               second
#define all(x)          x.begin(),x.end()
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef pair<int,int>   pii;


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
        return parent[x]=Find(parent[x]); // path compression
    }
    
    void Union(int a,int b) // union by size
    {
        a=Find(a), b=Find(b);
        if(size[a]<size[b]) swap(a,b);
        size[a]+=size[b];
        parent[b]=a;
    }
};



int main()
{
    int n,m; cin>>n>>m;
    vector<pair<int,pii>> adj; // adjacency list by weight
    for(int i=1;i<=m;i++)
    {
        int a,b,w; cin>>a>>b>>w;
        adj.pb({w,{a,b}});
        adj.pb({w,{b,a}});
    }
    DisjointSet ds(n);
    sort(all(adj)); // sorting edges by their weight
    int mstW=0;
    cout<<"Minimum spanning tree edges: "<<endl;
    for(auto x:adj)
    {
        int w=x.F;
        int a=x.S.F, b=x.S.S;
        if(ds.Find(a)!=ds.Find(b))
        {
            cout<<a<<" "<<b<<endl;
            mstW+=w;
            ds.Union(a,b);
        }
    }
    cout<<"Minimum cost: "<<mstW<<endl;
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
