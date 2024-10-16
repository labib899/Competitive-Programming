#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll B=256; // base

ll Hash(string s,int m)
{
    ll h=0,p=1;
    for(int i=m-1;i>=0;i--)
    {
        h=(h+s[i]*p)%mod;
        p=(p*B)%mod;
    }
    return h;
}

// will return the number of occurences of the pattern in the text
int match(string text,string pattern)
{
    int n=text.size(),m=pattern.size();
    ll hash_text=Hash(text,m), hash_pattern=Hash(pattern,m);
    
    // calculate p=B^(m-1)
    ll p=1;
    for(int i=1;i<=m-1;i++) p=(p*B)%mod;

    int ans=0;
    for(int i=0;i<=n-m;i++)
    {   
        if(hash_text==hash_pattern) ans++;
        if(i==n-m) break; // we don't need to calculate the next hash value
        hash_text=(B*(hash_text-text[i]*p) + text[i+m])%mod;
        if(hash_text<0) hash_text+=mod;
    }
    return ans;
}

void solve()
{
    string text,pattern; cin>>text>>pattern;
    cout<<match(text,pattern)<<endl;
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