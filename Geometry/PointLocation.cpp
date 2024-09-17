#include <bits/stdc++.h>
using namespace std;

typedef complex<double> Point;

#define X real()
#define Y imag()

double cross (Point a,Point b) { return (conj(a)*b).Y; }

void solve()
{
    double ax,ay,bx,by,cx,cy; cin>>ax>>ay>>bx>>by>>cx>>cy;
    Point a={ax,ay}, b={bx,by}, c={cx,cy};
    if(cross(c-a,c-b)>0) cout<<"LEFT"<<endl;
    else if(cross(c-a,c-b)<0) cout<<"RIGHT"<<endl;
    else cout<<"TOUCH"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1; cin>>t;
    while(t--) solve();
}