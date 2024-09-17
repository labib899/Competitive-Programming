#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define fastIO ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
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
void sieve();
void div();
map<int,int> factor(int n);
const int N=1e5+10;
vi prime(N,1);
vi lp(N,0),hp(N,0);
vi divisors[N];


int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    fastIO;
    sieve();
    div();
    ll t=1; //cin>>t;
    while(t--) solve();
}

void solve() {
    ll n; cin>>n;
    map<int,int> ans=factor(n);
    for(auto &x:ans) {
        for(int i=1;i<=x.second;i++) {
            cout<<x.first<<" ";
        }
    }
    cout<<endl;
    for(auto &x:divisors[n]) cout<<x<<" ";
    cout<<endl;
    for(int i=2;i<=n;i++) {
        cout<<i<<" "<<lp[i]<<" "<<hp[i]<<endl;
    }
}

void sieve() {
    //lowest and highest prime
    for(int i=2;i<=N;i++) {
        if(prime[i]==0) continue;
        lp[i]=hp[i]=i;
        for(int j=2*i;j<=N;j+=i) {
            prime[j]=0;
            if(lp[j]==0) lp[j]=i;
            hp[j]=i;
        }
    }
}

void div() {
    for(int i=2;i<=N;i++) {
        for(int j=i;j<=N;j+=i) divisors[j].pb(i);
    }
}

map<int,int> factor(int n) {
    map<int,int> f;
    for(int i=2;i*i<=n;i++) {
        while(n%i==0) {
            f[i]++;
            n/=i;
        }
    }
    if(n>1) f[n]++;
    return f;
}
