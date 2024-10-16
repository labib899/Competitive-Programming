#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll mod=1e9+7, inf=1e18;
vll a;
vvll dp;

ll mcm(int i,int j)
{
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll mini=inf;
    for(int k=i;k<=j-1;k++)
    {
        ll steps=(a[i-1]*a[k]*a[j])+mcm(i,k)+mcm(k+1,j);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}

void solve()
{
    ll n; cin>>n;
    a.resize(n);
    dp.resize(n,vll(n,-1));
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<mcm(1,n-1)<<endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    for(int i=1;i<=t;i++)
    {
        //printf("Case %d: ", i);
        solve();
    }
}