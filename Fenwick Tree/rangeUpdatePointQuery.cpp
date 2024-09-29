#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,q;
vector<int> vec,fen;

int sum(int i)
{
    int s=0;
    while(i>0) s+=fen[i],i-=(i&-i);
    return s;
}

void update(int i,int x)
{
    while(i<=n) fen[i]+=x,i+=(i&-i);
}

void range_update(int l,int r,int x)
{
    update(l,x);
    update(r+1,-x);
}

void solve()
{
    cin>>n>>q;
    vec.resize(n+1); fen.resize(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>vec[i];
        range_update(i,i,vec[i]);
    }
    while(q--)
    {
        int type; cin>>type;
        if(type==1)
        {
            int a,b,u; cin>>a>>b>>u;
            range_update(a,b,u);
        }
        else 
        {
            int k; cin>>k;
            cout<<sum(k)<<endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1; //cin>>t;
    while(t--) solve();
}