#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <bits/stdtr1c++.h>
// #include <bits/extc++.h>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
 
#define fastio                  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl                    "\n"
#define pb                      push_back
#define mp                      make_pair
#define mt                      make_tuple
#define all(x)                  x.begin(),x.end()
#define allrev(x)               x.rbegin(),x.rend()
#define rep(i,l,r)              for(ll i=l;i<r;i++)
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define print(v)                for(auto x:v) cout<<x<<" ";cout<<endl;
#define ff                      first
#define ss                      second
#define PQ                      priority_queue
#define __lcm(a,b)              (a/__gcd(a,b))*b
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
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll inf=LLONG_MAX;


#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<": ";_print(x);cerr<<endl;
#else 
#define debug(x);
#endif

void _print(int x) {cerr<<x;}
void _print(long long x) {cerr<<x;}
void _print(char x) {cerr<<x;}
void _print(string x) {cerr<<x;}
void _print(double x) {cerr<<x;}
void _print(long double x) {cerr<<x;}

template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> s);
template<class T> void _print(multiset<T> ms);
template<class T,class V> void _print(pair<T,V> p);
template<class T,class V> void _print(map<T,V> m);
template<class T> void _print(vector<T> v) {cerr<<"[ ";for(T x:v){_print(x);cerr<<" ";}cerr<<"]";}
template<class T> void _print(set<T> s) {cerr<<"[ ";for(T x:s){_print(x);cerr<<" ";}cerr<<"]";}
template<class T> void _print(multiset<T> ms) {cerr<<"[ ";for(T x:ms){_print(x);cerr<<" ";}cerr<<"]";}
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{";_print(p.ff);cerr<<",";_print(p.ss);cerr<<"}";}
template<class T,class V> void _print(map<T,V> m) {cerr<<"[ ";for(auto x:m) {_print(x);cerr<<" ";}cerr<<"]";}

// struct custom_hash 
// {
//     static uint64_t splitmix64(uint64_t x) 
//     {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const 
//     {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

// unordered_map<long long,int,custom_hash> safe_map;
// gp_hash_table<long long,int,custom_hash> safe_hash_table;



void solve()
{
    
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("error.txt","w",stderr);
    // #endif
    
    fastio;
    int t=1; cin>>t;
    for(int i=1;i<=t;i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}
