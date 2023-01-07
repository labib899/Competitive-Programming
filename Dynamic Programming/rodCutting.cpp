#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int N=1e3+10;
vector<vi> dp(N+1,vi(N+1,-1));

int rev(int i,int n,vi price)
{
    if(i==1) return n*price[1];
    if(dp[i][n]!=-1) return dp[i][n];
    int no=rev(i-1,n,price);
    int yes=0;
    if(i<=n) yes=price[i]+rev(i,n-i,price);
    return dp[i][n]=max(yes,no);
}

int main()
{
    int n; cin>>n;
    vi price(n+1);
    for(int i=1;i<=n;i++) cin>>price[i];
    cout<<rev(n,n,price)<<endl;
}



