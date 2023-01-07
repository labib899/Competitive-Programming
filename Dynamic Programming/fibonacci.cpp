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
const ll N=1e6+10;
vll dp(N,-1);
ll fibo(ll n) {
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibo(n-1)+fibo(n-2);
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    fastIO;
    //memset(dp,-1,sizeof(dp));
    ll t; cin>>t;
    while(t--) solve();
}

void solve() {
    ll n; cin>>n;
    cout<<fibo(n)<<endl;
}


