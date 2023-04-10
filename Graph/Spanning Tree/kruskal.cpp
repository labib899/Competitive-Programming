#include<bits/stdc++.h>
using namespace std;

#define fastIO              ios::sync_with_stdio(0);cin.tie(0);
#define pb                  push_back
#define mt                  make_tuple
#define all(x)              x.begin(),x.end()
typedef long long           ll;
typedef vector<ll>          vll;
typedef tuple<ll,ll,ll>     tlll;

const ll inf=1e18;
vll parent,sz;
vector<tlll> adj;

void make(ll n)
{
    sz.resize(n+2,1); // initially size of every component is 1
    parent.resize(n+2);
    for(int i=0;i<=n;i++) parent[i]=i;
}

ll Find(ll x)
{
    if(x==parent[x]) return x;
    return parent[x]=Find(parent[x]); // path compression, O(4a)
}

void Union(ll a,ll b) // Union by size, O(4a)
{
    a=Find(a),b=Find(b);
    if(sz[a]<sz[b]) swap(a,b);
    sz[a]+=sz[b]; // connect smaller to larger component
    parent[b]=a;
}

void kruskal(ll n)
{
    sort(all(adj)); // sorting by weight
    make(n);
    cout<<"Minimum spanning tree edges:"<<endl;
    ll cost=0;
    for(auto x:adj)
    {
        ll w=get<0>(x);
        ll a=get<1>(x), b=get<2>(x);
        if(Find(a)==Find(b)) continue; // don't connect if ultimate parent is same
        Union(a,b);
        cost+=w;
        cout<<a<<" "<<b<<endl;
    }
    cout<<"Total cost: "<<cost<<endl;
}

void solve()
{
   ll n,m; cin>>n>>m;
   for(int i=1;i<=m;i++)
   {
       ll a,b,w; cin>>a>>b>>w;
       adj.pb(mt(w,a,b));
       adj.pb(mt(w,b,a));
   }

   kruskal(n);
}


int main()
{
    fastIO;
    int t=1;// cin>>t;
    while(t--)
    {
        solve();
    }
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
