#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;

ll expo(ll x,ll p) 
{
    if(p==0) return 1;
    ll a=expo(x,p/2);
    a=(a*a)%mod;
    if(p&1) a=(a*x)%mod;
    return a;
}

void solve() 
{
    ll n,p; cin>>n>>p;
    cout<<expo(n,p)<<endl;
}

signed main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}