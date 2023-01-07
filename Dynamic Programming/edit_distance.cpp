#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int N=1e3+10;
const int M=1e3+10;
vector<vi> dp(N,vi(M,-1));
int ed(int i,int j,string s,string t);


int main()
{
    string s,t; cin>>s>>t;
    int n=s.size(),m=t.size();
    cout<<ed(n-1,m-1,s,t)<<endl;
}

int ed(int i,int j,string s,string t)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) dp[i][j]=ed(i-1,j-1,s,t);
    else dp[i][j]=min(ed(i-1,j-1,s,t),min(ed(i-1,j,s,t),ed(i,j-1,s,t)))+1;
    return dp[i][j];
}
