#include<bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;

int n,w;
vvi dp;
vi wt,val;

// iterative
void knapsack()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            int yes=(wt[i]<=j ? dp[i-1][j-wt[i]]+val[i]:0);
            int no=dp[i-1][j];
            dp[i][j]=max(yes,no);
        }
    }
}

void solve() 
{
    cin>>n>>w;
    wt.resize(n+1); val.resize(n+1);
    dp.resize(n+1,vi(w+1,0));
    for(int i=1;i<=n;i++) cin>>wt[i];
    for(int i=1;i<=n;i++) cin>>val[i];
    knapsack();
    cout<<dp[n][w]<<endl;
}

signed main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}

/*
7 15
2 3 5 7 1 4 1
10 5 15 7 6 18 3
*/


/* recursive
int knap(int i,int w)
{
    if(i==0)
    {
        if(wt[0]<=w) return val[0];
        else return 0;
    }
    if(dp[i][w]!=-1) return dp[i][w];
    int no=knap(i-1,w);
    int yes=0;
    if(wt[i]<=w) yes=val[i]+knap(i-1,w-wt[i]);
    return dp[i][w]=max(no,yes);
}
*/