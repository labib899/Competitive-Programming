#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> divisors[N+1];

void div() 
{
    for(int i=1;i<=N;i++)
        for(int j=i;j<=N;j+=i) divisors[j].push_back(i);
}

void solve() 
{
    int n; cin>>n;
    for(auto x:divisors[n]) cout<<x<<" "; cout<<endl;
}

signed main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    div();
    int t=1; //cin>>t;
    while(t--) solve();
}