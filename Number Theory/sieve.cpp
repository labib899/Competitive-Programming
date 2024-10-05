#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> prime(N+1,1);

void sieve() 
{
    for(int i=2;i<=N;i++) 
    {
        if(prime[i]==0) continue;
        for(int j=2*i;j<=N;j+=i) prime[j]=0;
    }
}

void solve() 
{
    int n; cin>>n;
    for(int i=2;i<=n;i++) if(prime[i]) cout<<i<<" ";
}

signed main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve();
    int t=1; //cin>>t;
    while(t--) solve();
}