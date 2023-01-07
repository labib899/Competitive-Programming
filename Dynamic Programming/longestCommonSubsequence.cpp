#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
const int M=1e3+10;
int dp[N][M];
int lcs(int i,int j,string s,string t)
{
    for(int j=0;j<M;j++) dp[0][j]=0;
    for(int i=0;i<N;i++) dp[i][0]=0;
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<M;j++)
        {
            if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[i][j];
}

string printLCS(string s,string t)
{
    int len=dp[s.size()-1][t.size()-1];
    string ans;
    int idx=len-1;
    for(int i=0;i<len;i++) ans+="$";
    int i=s.size()-1,j=t.size()-1;
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
    cout<<lcs(n-1,m-1,s,t)<<endl<<printLCS(s,t)<<endl;
}
