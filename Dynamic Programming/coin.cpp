#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll mod=1e9+7;
const ll N=1e6+5;
vector<ll> dp(N+1,INT_MAX),dp2(N+1,0),dp3(N+1,0),coins;

// minimizing coins
void minimize()
{   
    dp[0]=0;
    for(ll i=1;i<=N;i++)
    {
        for(auto c:coins)
        {
            if(i-c>=0) dp[i]=min(dp[i],dp[i-c]+1);
        }
    }
}

// counting solutions (unordered)
void count1()
{   
    dp2[0]=1;
    for(ll i=1;i<=N;i++)
    {
        for(auto c:coins)
        {
            if(i-c>=0) dp2[i]+=dp2[i-c],dp2[i]%=mod;
        }
    }
}

// counting solutions (ordered)
void count2()
{   
    dp3[0]=1;
    for(auto c:coins)
    {
        for(int i=1;i<=N;i++)
        {
            if(i-c>=0) dp3[i]+=dp3[i-c],dp3[i]%=mod;
        }
    }
}

 
void solve()
{
    ll n,x; cin>>n>>x;
    coins.resize(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    minimize();
    count1();
    count2();
    cout<<(dp[x]==INT_MAX ? -1:dp[x])<<endl;
    cout<<dp2[x]<<endl<<dp3[x]<<endl;

}
 
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}
