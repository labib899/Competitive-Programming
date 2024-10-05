#include<bits/stdc++.h>
using namespace std;

void solve() 
{
    int n,k; cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    
    unordered_map<int,int> freq;
    int ans=0,xorr=0;
    for(auto x:vec) 
    {
        xorr= xorr^x;
        freq[xorr]++;
        if(xorr==k) ans++;
        if(freq.find(xorr^k)!=freq.end()) ans+=freq[xorr^k];
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}