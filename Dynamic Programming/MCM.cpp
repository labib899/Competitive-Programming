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
typedef tuple<int,int,int>      tiii;
typedef tuple<ll,ll,ll>         tlll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


ll mod=1e9+7;
ll inf=1e18;
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
