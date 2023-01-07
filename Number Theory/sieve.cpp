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


void solve();
void sieve();
const int N=1e5+10;
vi prime(N,1);


int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    fastIO;
    sieve();
    ll t=1; //cin>>t;
    while(t--) solve();
}

void solve() {
    ll n; cin>>n;
    for(int i=2;i<=n;i++) {
        if(prime[i]) cout<<i<<" ";
    }
}

void sieve() {
    for(int i=2;i<=N;i++) {
        if(prime[i]==0) continue;
        for(int j=2*i;j<=N;j+=i) prime[j]=0;
    }
}
