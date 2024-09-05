#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


int lcs(int i,int j,string s,string t,vvi &dp)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) dp[i][j]=lcs(i-1,j-1,s,t,dp)+1;
    else dp[i][j]=max(lcs(i-1,j,s,t,dp),lcs(i,j-1,s,t,dp));
    return dp[i][j];
}


string printLCS(string s,string t,vvi &dp)
{
    int n=s.size(),m=t.size();
    int len=dp[n-1][m-1];
    string ans;
    for(int i=0;i<len;i++) ans+="$";
    int i=n-1,j=m-1;
    int idx=len-1;
    while(i>=0 && j>=0)
    {
        if(s[i]==t[j]) ans[idx--]=s[i],i--,j--;
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    return ans;
}


int main()
{
    string s,t; cin>>s>>t;
    int n=s.size(),m=t.size();
    vvi dp(n+2,vi(m+2,-1));
    cout<<lcs(n-1,m-1,s,t,dp)<<endl<<printLCS(s,t,dp)<<endl;
}


/*
int lcs(string s,string t,vvi &dp)
{
    int n=s.size(),m=t.size();
    for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=m;j++)
     {
         if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
         else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
     }
    }
    return dp[n][m];
}
*/
