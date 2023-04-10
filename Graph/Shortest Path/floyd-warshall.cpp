#include<bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef vector<ll>      vll;

const ll inf=1e18;
vector<vll> dist;

void floyd(ll n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
           for(int j=1;j<=n;j++)
                if(dist[i][k]<inf && dist[k][j]<inf) // to handle negative weights
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

void solve()
{
    ll n,m,q; cin>>n>>m>>q;
    dist.resize(n+2,vll(n+2,inf));
    for(int i=1;i<=m;i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        dist[a][b]=dist[b][a]=min(c,dist[a][b]); // for multiple edges
    }
    for(int i=1;i<=n;i++) dist[i][i]=0;

    floyd(n);
    while(q--)
    {
        ll a,b; cin>>a>>b;
        // if(a==b && dist[a][b]<0) then negative cycle exists...
        if(dist[a][b]==inf) cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }
}

int main()
{
    int t=1; //cin>>t;
    while(t--)
    {
        solve();
    }
}
