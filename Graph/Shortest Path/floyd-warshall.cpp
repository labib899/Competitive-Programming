#include<bits/stdc++.h>
using namespace std;


typedef long long       ll;
typedef vector<ll>      vll;
typedef vector<vll>     vvll;


int main()
{
    ll n,m; cin>>n>>m;
    vvll adj(n+2,vll(n+2)), distance(n+2,vll(n+2,INT_MAX));
    for(int i=1;i<=m;i++)
    {
        int a,b,w; cin>>a>>b>>w;
        adj[a][b]=w;
    }
    // initializing distance matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) distance[i][j]=0;
            else if(adj[i][j]) distance[i][j]=adj[i][j];
        }
    }
    // floyed-warshall algo
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
            }
        }
    }

    // checking negative cycle
    for(int i=0;i<n;i++)
    {
        if(distance[i][i]<0) 
        {
            cout<<"Negative Cycle"<<endl;
            return -1;
        }
    }
    // printing solution
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) 
        {
            if(distance[i][j]==INT_MAX) cout<<"INF ";
            else cout<<distance[i][j]<<" ";
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
