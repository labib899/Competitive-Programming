#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int N=1e5+10;
vi dp(N,-1);
vi ans(N,0);
int solve(int s,vi coins)
{
    //top down
    if(s<=0) return 0;
    if(dp[s]!=-1) return dp[s];
    int ans=INT_MAX;
    for(auto x:coins) dp[s]=ans=min(ans,solve(s-x,coins)+1);
    return dp[s];
}

int count(int sum,vi coins)
{
    ans[0]=1;
    //bottom up
    for(int i=1;i<=N;i++)
    {
        for(auto x:coins)
        {
            if(i-x>=0) ans[i]+=ans[i-x];
        }
    }
    return ans[sum];
}

int main()
{
    int n; cin>>n;
    vi coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    int s; cin>>s;
    cout<<solve(s,coins)<<endl;
    cout<<count(s,coins)<<endl;
}


