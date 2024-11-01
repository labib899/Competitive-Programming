#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
#define X real()
#define Y imag()
const double pi=acos(-1);

vector<cd> fft(vector<cd> p, int n, int d)
{
    if(n==1) return p;
    vector<cd> pe,po;
    for(int i=0;2*i<n;i++)
    {
        pe.push_back(p[2*i]);
        po.push_back(p[2*i+1]);
    }
    pe=fft(pe,n/2,d);
    po=fft(po,n/2,d);

    double angle=(d==1 ? 2*pi/n:-2*pi/n);
    cd w(1,0),wd(cos(angle),sin(angle));
    for(int i=0;i<n/2;i++)
    {
        p[i]=pe[i]+w*po[i];
        p[i+n/2]=pe[i]-w*po[i];
        w*=wd;
    }
    return p;
}

vector<ll> mul(vector<ll> &a, vector<ll> &b)
{
    vector<cd> x(a.begin(),a.end()),y(b.begin(),b.end());

    int n=1;
    while(n<a.size()+b.size()) n*=2; // nearest power of 2
    x.resize(n);
    y.resize(n);

    x=fft(x,n,1),y=fft(y,n,1); // fft
    vector<cd> z(n);
    for(int i=0;i<n;i++) z[i]=x[i]*y[i]; // multiply polynomials
    z=fft(z,n,-1); // inverse fft

    vector<ll> res(n);
    for(int i=0;i<n;i++) res[i]=llround(z[i].X/n);
    return res;
}

void solve()
{
    int n; cin>>n;
    vector<ll> a(n+1),b(n+1);
    for(int i=0;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n;i++) cin>>b[i];

    vector<ll> ans=mul(a,b);
    for(int i=0;i<=2*n;i++) cout<<ans[i]<<" "; cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1; cin>>t;
    while(t--) solve();
}