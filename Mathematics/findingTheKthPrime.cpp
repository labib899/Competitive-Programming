#include <bits/stdc++.h>
using namespace std;

const int N=87e6+10;
bool prime[N];
vector<int> ans;

void sieve()
{   
    prime[0]=prime[1]=true;
    for(int i=2;i*i<=N;i++)
    {   
        if(prime[i]==true) continue;
        for(int j=i*i;j<=N;j+=i) prime[j]=true;
    }
    for(int i=2;i<=N;i++)
    {
        if(prime[i]==false) ans.push_back(i);
    }
}

void solve()
{
    int k; cin>>k;
    cout<<ans[k-1]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sieve();
    int t=1; cin>>t;
    while(t--) solve();
}