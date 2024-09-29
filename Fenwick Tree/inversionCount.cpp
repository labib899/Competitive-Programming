#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,q,cnt; 
vector<int> vec,fen;
map<int,int> mp;

void compress()
{   
    cnt=0;
    for(auto x:mp) mp[x.first]=cnt++;
    for(int i=1;i<=n;i++) vec[i]=mp[vec[i]];
}

int sum(int i)
{
    int s=0;
    for(;i>0;i-=(i&-i)) s+=fen[i];
    return s;
}

void update(int i,int x)
{   
    for(;i<=n;i+=(i&-i)) fen[i]+=x;
}

void solve()
{
    cin>>n;
    vec.resize(n+1); fen.resize(n+1,0);
    mp[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>vec[i]; 
        mp[vec[i]]=0;
    }
    compress();
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=sum(n)-sum(vec[i]);
        update(vec[i],1);
    }
    cout<<ans<<endl;
    mp.clear(); fen.clear();
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1; cin>>t;
    while(t--) solve();
}
