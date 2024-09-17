#include <bits/stdc++.h>
using namespace std;

typedef complex<long double> P;

#define X real()
#define Y imag()

long double cross (P a,P b) { return (conj(a)*b).Y; }  // result of cross product

void solve()
{
    int n; cin>>n;
    vector<P> vec;
    for(int i=0;i<n;i++) 
    {
        long double x,y; cin>>x>>y;
        vec.push_back({x,y});
    }
    long double area=0.0;
    for(int i=0;i<n;i++) area+=cross(vec[i],vec[(i+1)%n]);
    area=abs(area)/2;
    cout<<area<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1; //cin>>t;
    while(t--) solve();
}