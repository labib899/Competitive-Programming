#include<bits/stdc++.h>
using namespace std;

#define min3(a,b,c) min(a,min(b,c))
typedef vector<int> vi;
typedef vector<vi> vvi;


int ed(int i,int j,string s,string t,vvi &dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) dp[i][j]=ed(i-1,j-1,s,t,dp);
    else dp[i][j]=1+min3(ed(i-1,j-1,s,t,dp),ed(i-1,j,s,t,dp),ed(i,j-1,s,t,dp));
    return dp[i][j];
}


int main()
{
    string s,t; cin>>s>>t;
    int n=s.size(),m=t.size();
    vvi dp(n+2,vi(m+2,-1));
    cout<<ed(n-1,m-1,s,t,dp)<<endl;
}


/*
int ed(string s,string t,vvi &dp)
{
    int n=s.size(),m=t.size();
    for(int j=0;j<=m;j++) dp[0][j]=j;
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=m;j++)
     {
         if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
         else dp[i][j]=1+min3(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
     }
    }
    return dp[n][m];
}
*/
