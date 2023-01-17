#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int N=1e3+10;
const int M=1e3+10;
vector<vi> dp(N,vi(M,-1));
string s,t;


int lcs(int i,int j)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) dp[i][j]=lcs(i-1,j-1)+1;
    else dp[i][j]=max(lcs(i-1,j),lcs(i,j-1));
    return dp[i][j];
}

string printLCS()
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
    cin>>s>>t;
    int n=s.size(),m=t.size();
    cout<<lcs(n-1,m-1)<<endl;
    cout<<printLCS()<<endl;
}


