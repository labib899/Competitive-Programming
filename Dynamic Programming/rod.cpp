#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi price;

// top down
int rev(int n,vi &dp)
{
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        int c=price[i]+rev(n-i,dp);
        ans=max(ans,c);
    }
    return dp[n]=ans;
}


int main()
{
    int n; cin>>n;
    price.resize(n+1);
    for(int i=1;i<=n;i++) cin>>price[i];
    vi dp(n+2,-1);
    cout<<rev(n,dp)<<endl;
}



/* bottom up
int rev(int n)
{
    dp[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            dp[i]=max(dp[i],price[j]+dp[i-j]);
    return dp[n];
}
*/
