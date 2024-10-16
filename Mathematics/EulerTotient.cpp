#include <bits/stdc++.h>
using namespace std;

const int N=1e7+2;
vector<int> phi(N+1),pref(N+1);

void init() // O(nlog(logn)), for phi(1) to phi(n)
{
    for(int i=1;i<=N;i++) phi[i]=i;
    for(int i=2;i<=N;i++)
    {
        if(phi[i]!=i) continue;
        for(int j=i;j<=N;j+=i) phi[j]/=i,phi[j]*=(i-1);
    }
    for(int i=1;i<=N;i++) pref[i]=pref[i-1]+phi[i];
}

void solve()
{
    int a,b; cin>>a>>b;
    cout<<pref[b]-pref[a-1]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    init();
    int t=1; //cin>>t;
    while(t--) solve();
}


/* O(sqrt(n)), only for phi(n)
int phi(int n) 
{   
    int ans=n;
    for(int i=2;i*i<=n;i++)
    {   
        if(n%i) continue;
        while(n%i==0) n/=i;
        ans-=ans/i;
    }
    if(n>1) ans-=ans/n;
    return ans;
}
*/