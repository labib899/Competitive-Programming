#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<ll> Point;

#define X real()
#define Y imag()

ll orientation(Point a,Point b, Point c)
{
    ll res=(b.Y-a.Y)*(c.X-b.X)-(c.Y-b.Y)*(b.X-a.X);
    if(res<0) return -1;  // anticlockwise
    else if(res==0) return 0;  // collinear
    else return 1;  // clockwise
}

bool project(ll a,ll b,ll c,ll d)
{
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    return max(a,c)<=min(b,d);
}

void solve()
{
    ll ax,ay,bx,by,cx,cy,dx,dy; cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
    Point a={ax,ay}, b={bx,by}, c={cx,cy}, d={dx,dy};
    ll o1=orientation(a,b,c), o2=orientation(a,b,d);
    ll o3=orientation(c,d,a), o4=orientation(c,d,b);
    if(o1!=o2 and o3!=o4) cout<<"YES"<<endl;
    else if(o1==0 and o4==0)
    {
        if(project(a.X,b.X,c.X,d.X) and project(a.Y,b.Y,c.Y,d.Y)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1; cin>>t;
    while(t--) solve();
}