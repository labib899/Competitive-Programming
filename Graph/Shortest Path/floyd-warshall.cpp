#include<bits/stdc++.h>
using namespace std;

#define inf             1e18
typedef long long       ll;
typedef vector<ll>      vll;
typedef vector<vll>     vvll;

vvll dist;
ll n,m;

void floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}


int main()
{
    cin>>n>>m;
    dist.resize(n+2,vll(n+2,inf));
    for(int i=1;i<=m;i++)
    {
        ll a,b,w; cin>>a>>b>>w;
        dist[a][b]=w;
        dist[b][a]=w; // for undirected graphs
    }
    // initializing distance matrix
    for(int i=0;i<n;i++) dist[i][i]=0;
    // floyd warshall algo
    floyd();

    // checking negative cycle
    /*for(int i=0;i<n;i++)
    {
        if(dist[i][i]<0) 
        {
            cout<<"Negative Cycle"<<endl;
            return -1;
        }
    }*/
    // printing solution
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) 
        {
            if(dist[i][j]==inf) cout<<"inf ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}


/*
4 4
0 1 5
0 3 10
1 2 3
2 3 1
*/