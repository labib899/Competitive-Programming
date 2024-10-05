#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

const ll N=1e3+10;
ll mod=1e9+7;
vvll dp(N,vll(N,-1));


ll ncr(ll n,ll r)
{
    if(r==0 || r==n) return 1;
    if(r==1) return n;
    if(dp[n][r]!=-1) return dp[n][r]%mod;
    return dp[n][r]=(ncr(n-1,r-1)+ncr(n-1,r))%mod;
}


signed main()
{
    ll n,r; cin>>n>>r;
    cout<<ncr(n,r)<<endl;
}
