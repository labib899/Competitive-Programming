#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=1e9+7;
const ll N=1e6+5;
vector<ll> dp(N+1,0);

void func(ll n)
{   
    dp[0]=1;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(i<j) break;
            dp[i]+=dp[i-j];
            dp[i]%=mod;
        }
    }
}

void solve()
{
    ll n; cin>>n;
    func(n);
    cout<<dp[n]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}