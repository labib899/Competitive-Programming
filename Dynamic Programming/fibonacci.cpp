#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N=1e6+10;
vector<ll> dp(N,-1);
ll fibo(ll n) 
{
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibo(n-1)+fibo(n-2);
}

void solve() 
{
    ll n; cin>>n;
    cout<<fibo(n)<<endl;
}

signed main() 
{   
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}

