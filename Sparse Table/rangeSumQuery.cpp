#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,logn,q;
vector<ll> vec;
vector<vector<ll>> st; // sparse table

// O(nlogn)
void build()
{
    for(int i=1;i<=n;i++) st[i][0]=vec[i];
    for(int j=1;j<logn;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++) 
            st[i][j]=st[i][j-1]+st[i+(1<<(j-1))][j-1];
    }
}

// O(logn)
ll query(int l,int r)
{
    ll sum=0;
    for(int j=logn;j>=0;j--)
    {
        if(l+(1<<j)-1<=r) sum+=st[l][j],l+=(1<<j);
    }
    return sum;
}

void solve()
{
    cin>>n>>q;
    logn=log2(n)+1;
    vec.resize(n+1); st.resize(n+1,vector<ll>(logn));
    for(int i=1;i<=n;i++) cin>>vec[i];
    build();
    while(q--)
    {
        int l,r; cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
}

signed main()
{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;//cin>>t;
    while(t--) solve();
}