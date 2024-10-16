#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> prime(N+1,1),lp(N+1,0),hp(N+1,0);

//lowest and highest prime
void sieve() 
{
    for(int i=2;i<=N;i++) 
    {
        if(prime[i]==0) continue;
        lp[i]=hp[i]=i;
        for(int j=2*i;j<=N;j+=i) 
        {
            prime[j]=0;
            if(lp[j]==0) lp[j]=i;
            hp[j]=i;
        }
    }
}

void solve() 
{
    int n; cin>>n;
    for(int i=2;i<=n;i++) cout<<i<<" "<<lp[i]<<" "<<hp[i]<<endl;
}

signed main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve();
    int t=1; //cin>>t;
    while(t--) solve();
}