#include<bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> tiii;

vector<int> parent,sz;

void make(int x) { parent[x]=x,sz[x]=1; }

int Find(int x)
{
    if(x==parent[x]) return x;
    return parent[x]=Find(parent[x]);  // path compression
}

void Union(int a,int b)  // union by size
{
    a=Find(a), b=Find(b);
    if(a!=b)
    {
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}


signed main()
{
    int n,m; cin>>n>>m;
    parent.resize(n+1); sz.resize(n+1);
    for(int i=0;i<=n;i++) make(i);
    vector<tiii> adj; // adjacency list by weight
    for(int i=1;i<=m;i++)
    {
        int a,b,w; cin>>a>>b>>w;
        adj.push_back(make_tuple(w,a,b));
        adj.push_back(make_tuple(w,b,a));
    }

    sort(adj.begin(),adj.end()); // sorting edges by their weight
    int cost=0;
    cout<<"Minimum spanning tree edges: "<<endl;
    for(auto x:adj)
    {
        int w=get<0>(x);
        int a=get<1>(x), b=get<2>(x);
        if(Find(a)!=Find(b))
        {
            cost+=w;
            Union(a,b);
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
