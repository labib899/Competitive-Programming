#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define fastIO ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef priority_queue<ll> pqll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int N=1e5+10;
vi graph[N+1]; //adjacency list
int vis[N+1];//dfs,bfs
int level[N+1]; //bfs
void solve();
void dfs(int node);
void bfs(int node);

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    fastIO;
    ll t; cin>>t;
    while(t--) solve();
}

void solve() {
    int m; cin>>m;
    for(ll i=1;i<=m;i++) {
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
}


void dfs(int node) {
    if(vis[node]) return;
    vis[node]=1;
    for(auto c:graph[node]) dfs(c);
}

void bfs(int node) {
    queue<int> q;
    q.push(node);
    vis[node]=1;
    
    while(!q.empty()) {
        int p=q.front(); q.pop();
        for(auto c:graph[p]) {
            if(!vis[c]) {
                q.push(c);
                vis[c]=1;
                level[c]=level[p]+1;
            }
        }
    }
}
