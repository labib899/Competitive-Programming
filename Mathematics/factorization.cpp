#include<bits/stdc++.h>
using namespace std;

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
}

signed main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}