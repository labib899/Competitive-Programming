#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define fastIO                  ios::sync_with_stdio(0);cin.tie(0);
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen(x,"w",stdout)
#define endl                    "\n"
#define pb                      push_back
#define mp                      make_pair
#define mt                      make_tuple
#define all(x)                  x.begin(),x.end()
#define rep(i,l,r)              for(ll i=l;i<r;i++)
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define print(v)                for(auto x:v) cout<<x<<" ";cout<<endl;
#define ff                      first
#define ss                      second
#define PQ                      priority_queue
typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef vector<ll>              vll;
typedef vector<vll>             vvll;
typedef vector<string>          vs;
typedef pair<int,int>           pii;
typedef pair<ll,ll>             pll;
//typedef tuple<int,int,int>      tiii;
//typedef tuple<ll,ll,ll>         tlll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


ll mod=1e9+7;
ll inf=1e18;
ll maxSum=1e5+10; // max allowed sum of coins
vll coins,dp,dp1;

ll cnt(ll sum) // top down
{
    if(sum<0) return inf; // we can not form negative sum
    if(sum==0) return 0; // no coin is needed to form sum 0
    if(dp[sum]!=-1) return dp[sum];
    ll ans=inf;
    for(auto x:coins) ans=min(ans,cnt(sum-x)+1);
    return dp[sum]=ans;
}

ll cnt1(ll sum) // bottom up
{
    dp1[0]=0; // no coin is needed to form sum 0
    for(int i=1;i<=sum;i++)
    {
        for(auto x:coins)
        {
            if(i-x>=0) dp1[i]=min(dp1[i],dp1[i-x]+1);
        }
    }
    return dp1[sum];
}


void solve()
{
    ll n; cin>>n;
    coins.resize(n);
    dp.resize(maxSum,-1); // top down
    dp1.resize(maxSum,inf); // bottom up
    for(int i=0;i<n;i++) cin>>coins[i];
    ll sum; cin>>sum;
    cout<<cnt(sum)<<endl;
    cout<<cnt1(sum)<<endl;
}


int main()
{
#ifndef ONLINE_JUDGE
    //fRead("input.txt");
    //fWrite("output.txt");
#endif
    fastIO;
    int t=1; //cin>>t;
    for(int i=1;i<=t;i++)
    {
        //printf("Case %d: ", i);
        solve();
    }
}
