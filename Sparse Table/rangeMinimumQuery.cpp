#include <bits/stdc++.h>
using namespace std;

int n,logn,q;
vector<int> vec;
vector<vector<int>> st; // sparse table

// O(nlogn)
void build()
{
    for(int i=1;i<=n;i++) st[i][0]=vec[i];
    for(int j=1;j<logn;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++) 
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
}

// O(1)
int query(int l,int r)
{
    int len=r-l+1;
    int j=log2(len);
    return min(st[l][j],st[r-(1<<j)+1][j]);
}

void solve()
{
    cin>>n>>q;
    logn=log2(n)+1;
    vec.resize(n+1); 
    st.resize(n+1,vector<int>(logn));
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