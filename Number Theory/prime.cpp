#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> prime(N+1,1),lp(N+1,0),hp(N+1,0),divisors[N+1];

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

void div() 
{
    for(int i=1;i<=N;i++)
        for(int j=i;j<=N;j+=i) divisors[j].push_back(i);
}

map<int,int> factor(int n) 
{
    map<int,int> f;
    for(int i=2;i*i<=n;i++) 
    {
        while(n%i==0) f[i]++, n/=i;
    }
    if(n>1) f[n]++;
    return f;
}

void solve() 
{
    int n; cin>>n;
    map<int,int> ans=factor(n);
    for(auto x:ans) cout<<x.first<<" "<<x.second<<endl;
    for(auto x:divisors[n]) cout<<x<<" "; cout<<endl;
    for(int i=2;i<=n;i++) cout<<i<<" "<<lp[i]<<" "<<hp[i]<<endl;
}

signed main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve();
    div();
    int t=1; //cin>>t;
    while(t--) solve();
}