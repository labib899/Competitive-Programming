#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,q;
vector<int> vec,fen1,fen2;

int sum(vector<int> &fen,int i)
{
    int s=0;
    while(i>0) s+=fen[i],i-=(i&-i);
    return s;
}

int prefsum(int i)
{
    return sum(fen1,i)*i-sum(fen2,i);
}

void update(vector<int> &fen,int i,int x)
{
    while(i<=n) fen[i]+=x,i+=(i&-i);
}

void range_update(int l,int r,int x)
{
    update(fen1,l,x); update(fen1,r+1,-x);
    update(fen2,l,x*(l-1)); update(fen2,r+1,-x*r); 
}

void solve()
{
    cin>>n>>q;
    vec.resize(n+1); fen1.resize(n+1,0); fen2.resize(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>vec[i];
        range_update(i,i,vec[i]);
    }
    while(q--)
    {
        int type,a,b; cin>>type>>a>>b;
        if(type==1)
        {
            int x; cin>>x;
            range_update(a,b,x);
        }
        else cout<<prefsum(b)-prefsum(a-1)<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1; //cin>>t;
    while(t--) solve();
}

/*
5 5
2 3 9 4 6
1 2 5 3
1 1 5 10
2 2 5
1 4 5 -7
2 3 5
*/