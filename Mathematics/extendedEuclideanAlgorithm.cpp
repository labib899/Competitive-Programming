#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b,int &x,int &y)
{
    if(b==0) { x=1,y=0; return a; }
    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1,y=x1-y1*(a/b);
    return d;
}

void solve()
{
    int a,b; cin>>a>>b;
    int x,y,g=gcd(a,b,x,y);
    cout<<x<<" "<<y<<endl; // ax+by=gcd(a,b)
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}