#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,q; 
vector<int> vec,fen;

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
    cin>>n>>q;
    vec.resize(n+1); fen.resize(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>vec[i]; 
        update(i,vec[i]);
    }
    while(q--)
    {
        int type,a,b; cin>>type>>a>>b;
        if(type==1) update(a,b-vec[a]),vec[a]=b;
        else cout<<sum(b)-sum(a-1)<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1; //cin>>t;
    while(t--) solve();
}