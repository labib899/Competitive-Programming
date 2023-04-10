#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi>  vvi;

const int N=1e3+10;
vi cuts(N);
vvi dp(N,vi(N,-1));

int cost(int start,int end)
{
    if(dp[start][end]!=-1) return dp[start][end];
    int mini=INT_MAX;
    bool f=false;
    for(auto x:cuts)
    {
        if(x>start && x<end) 
        {       
            f=true;
            int c=(end-start)+cost(start,x)+cost(x,end);
            mini=min(mini,c);
        }
    }
    if(!f) return dp[start][end]=0;
    else return dp[start][end]=mini;
}


int main()
{
    int len,n; cin>>len>>n; // n is the number of cutting points
    cuts.resize(n+2);
    for(int i=1;i<=n;i++) cin>>cuts[i];
    sort(cuts.begin(),cuts.end());
    cout<<cost(0,len)<<endl;
}




/* bottom up
int cost(int n)
{
    for(int i=n+1;i>=0;i--)
    {
        for(int j=0;j<=n+1;j++)
        {
            if(i+1>=j) continue;
            dp[i][j]=INT_MAX;
            for(int x=i+1;x<j;x++)
            {
                dp[i][j]=min(dp[i][j],cuts[j]-cuts[i]+dp[i][x]+dp[x][j]);
            }
        }
    }
    return dp[0][n+1];
}
*/
