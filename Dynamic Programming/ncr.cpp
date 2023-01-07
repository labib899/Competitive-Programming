#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

const ll N=1e3+10;
const ll M=1e3+10;
ll mod=1e9+7;
vector<vi> dp(N+1,vi(M+1,-1));
ll ncr(int n,int r);


int main()
{
    int n,r; cin>>n>>r;
    cout<<ncr(n,r)<<endl;
}

ll ncr(int n,int r)
{
    if(r==0 || r==n) return 1;
    if(r==1) return n;
    if(dp[n][r]!=-1) return dp[n][r]%mod;
    return dp[n][r]=(ncr(n-1,r-1)+ncr(n-1,r))%mod;
}
