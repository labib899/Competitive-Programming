#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

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
    DisjointSet ds(n);
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        ds.Union(a,b);
    }
    int q; cin>>q;
    while(q--)
    {
        int x,y; cin>>x>>y;
        if(ds.Find(x)==ds.Find(y)) cout<<"YES"<<endl; // belongs to the same component
        else cout<<"NO"<<endl;
    }
}


/*
 7 6
 1 2
 2 3
 4 5
 6 7
 5 6
 4 7
*/
