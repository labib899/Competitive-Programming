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

ll mod=1e9+7;

void solve();
ll pow(ll x,ll p,ll m);

int main() {
    fastIO;
    ll t=1; //cin>>t;
    while(t--) solve();
}

void solve() {
    ll n,p; cin>>n>>p;
    cout<<pow(n,p,mod)<<endl;
}

ll pow(ll x,ll p,ll m) {
    if(p==0) return 1%m;
    ll a=pow(x,p/2,m);
    a=(a*a)%m;
    if(p&1) a=(a*x)%m;
    return a;
}
