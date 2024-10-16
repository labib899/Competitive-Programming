#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

const ll mod=1e9+7;

matrix mul(matrix &a,matrix &b)
{
    ll n=a.size();
    matrix ans(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            for(ll k=0;k<n;k++) ans[i][j]+=a[i][k]*b[k][j], ans[i][j]%=mod;
        }
    }
    return ans;
}

matrix power(matrix &a,ll n)
{
    if(n==0)
    {   
        ll sz=a.size();
        matrix I(sz,vector<ll>(sz,0));
        for(ll i=0;i<sz;i++) I[i][i]=1;
        return I;
    }
    if(n==1) return a;
    matrix x=power(a,n/2);
    x=mul(x,x);
    if(n&1) x=mul(x,a);
    return x;
}

void solve()
{
    ll n,m; cin>>n>>m;
    matrix a(n,vector<ll>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>a[i][j];

    matrix ans=power(a,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}