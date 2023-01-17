#include<bits/stdc++.h>
using namespace std;

#define min3(a,b,c) min(a,min(b,c))
typedef vector<int> vi;

const int N=1e3+10;
const int M=1e3+10;
vector<vi> dp(N,vi(M,-1));
string s,t;


int ed(int i,int j)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) dp[i][j]=ed(i-1,j-1);
    else dp[i][j]=1+min3(ed(i-1,j-1),ed(i-1,j),ed(i,j-1));
    return dp[i][j];
}


int main()
{
    cin>>s>>t;
    int n=s.size(),m=t.size();
    cout<<ed(n-1,m-1)<<endl;
}

