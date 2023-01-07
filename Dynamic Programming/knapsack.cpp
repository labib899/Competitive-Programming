#include<bits/stdc++.h>
using namespace std;
 
#define fastIO ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define forn(j,n,x) for(ll i=j;i<n;i+=x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;


void solve();
const int N=1e3+10;
vvi dp(N,vi(N,-1));
vi wt(N),val(N);

int knap(int i,int w)
{
    if(i==0)
    {
        if(wt[0]<=w) return val[0];
        else return 0;
    }
    if(dp[i][w]!=-1) return dp[i][w];
    int no=knap(i-1,w);
    int yes=0;
    if(wt[i]<=w) yes=val[i]+knap(i-1,w-wt[i]);
    return dp[i][w]=max(no,yes);
}



int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    fastIO;
    int t=1; //cin>>t;
    while(t--) solve();
}

void solve() {
    int n,w; cin>>n>>w;
    forn(0,n,1) cin>>wt[i]>>val[i];
    cout<<knap(n-1,w)<<endl;
}


/*
 7 15
 2 10
 3 5
 5 15
 7 7
 1 6
 4 18
 1 3
 */
