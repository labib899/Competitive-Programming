#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define fastIO ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define forn(j,n,x) for(ll i=j;i<n;i+=x)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef priority_queue<ll> pqll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


void solve();
ll mod=1e9+7;
ll pow(ll a,ll b,ll m);


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    fastIO;
    int t=1; cin>>t;
    while(t--) solve();
}

void solve()
{
    ll a,b; cin>>a>>b;
    cout<<pow(a,b,mod)<<endl;
}

ll pow(ll a,ll b,ll m)
{   
    a=a%m; // if a is very large
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%m;
        a=(a*a)%m;
        b=b>>1;
    }
    return ans;
}
