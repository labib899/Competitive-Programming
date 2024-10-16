#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll B=256; // base
vector<ll> h,p;

void prefHash(string text)
{
    int n=text.size();
    h.resize(n);
    p.resize(n);

    p[0]=1;
    for(int i=1;i<n;i++) p[i]=(p[i-1]*B)%mod;

    h[0]=text[0];
    for(int i=1;i<n;i++) h[i]=(h[i-1]*B+text[i])%mod;
}

ll Hash(ll a,ll b)
{   
    if(a==0) return h[b];
    return (h[b]-(h[a-1]*p[b-a+1])%mod+mod)%mod;
}

void solve()
{
    string text; cin>>text;
    int n=text.size();
    prefHash(text);
    for(int i=0;i<n-1;i++)
    {
        if(Hash(0,i)==Hash(n-1-i,n-1)) cout<<i+1<<" ";
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1; //cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}