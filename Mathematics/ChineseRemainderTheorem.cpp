#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

pll exteuc(ll a,ll b) // extended euclidean algo to find (x,y) for ax+by=gcd(a,b)
{
    if(b==0) return {1,0};
    pll d=exteuc(b,a%b);
    return {d.second,d.first-d.second*(a/b)};
}

ll modinv(ll a,ll m)
{
    ll ans=exteuc(a,m).first;
    return (ans+m)%m;
}

void solve()
{
    ll n; cin>>n;
    vector<ll> m(n),a(n);
    ll M=1;
    for(int i=0;i<n;i++)
    {
        cin>>m[i]>>a[i];
        M*=m[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll x=M/m[i],invx=modinv(x,m[i]);
        ans=ans+(a[i]*x*invx); ans%=M;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1; cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<": ";
        solve();
    }
}