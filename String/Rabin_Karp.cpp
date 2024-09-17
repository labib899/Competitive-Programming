#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll b=256; // base 

ll Hash(string s,int m)
{
    ll h=0,pow=1;
    for(int i=m-1;i>=0;i--)
    {
        h=(h+s[i]*pow)%mod;
        pow=(pow*b)%mod;
    }
    return h;
}

// will return the number of occurences of the pattern in the text
int match(string text,string pattern)
{
    int n=text.size(),m=pattern.size();
    ll hash_text=Hash(text,m);
    ll hash_pattern=Hash(pattern,m);
    
    // calculate pow=b^(m-1)
    ll pow=1;
    for(int i=1;i<=m-1;i++) pow=(pow*b)%mod;

    int ans=0;
    for(int i=0;i<=n-m;i++)
    {   
        if(hash_text==hash_pattern) ans++;
        if(i==n-m) continue; // we don't need to calculate the next hash value
        hash_text=(b*(hash_text-text[i]*pow) + text[i+m])%mod;
        if(hash_text<0) hash_text+=mod;
    }
    return ans;
}

int main()
{
    string text,pattern; cin>>text>>pattern;
    cout<<match(text,pattern)<<endl;
}