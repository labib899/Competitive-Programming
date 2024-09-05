#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define fastIO ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define forn(j,n,x) for(ll i=j;i<n;i+=x)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef priority_queue<ll> pqll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


void solve();
vector<vi> graph; 
vi color;
bool bfs(int node);


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    fastIO;
    int t=1; cin>>t;
    while(t--) solve();
}

void solve()
{
    int n,m; cin>>n>>m; // n nodes, m edges
    graph.resize(n);
    color.resize(n,-1);
    for(int i=0;i<m;i++) 
    {
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bool bi=1;
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1) // if not visited
        {
            bi &=bfs(i);
        }
    }
    cout<<(bi==1 ? "Yes":"No")<<endl;
    color.clear();
}

bool bfs(int node)
{
    queue<int> q;
    q.push(node);
    color[node]=0;
    
    while(!q.empty())
    {
        int p=q.front(); q.pop();
        for(auto c:graph[p])
        {
            if(color[c]==-1) // if not visited
            {
                q.push(c);
                color[c]=1-color[p];
            }
            else if(color[c]==color[p])
            {
                return false;
            }
        }
    }
    return true;
}

