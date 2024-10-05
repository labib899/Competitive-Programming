#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;

ll expo(ll a,ll b)
{
    a%=mod; // if a is very large
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return ans;
}

void solve()
{
    ll a,b; cin>>a>>b;
    cout<<expo(a,b)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}
