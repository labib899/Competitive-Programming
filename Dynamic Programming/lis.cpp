#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int N=1e3+10;
vi v(N);
vvi dp(N,vi(N+1,-1));

int lis(int i,int prev)
{
    if(i==N) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int no=lis(i+1,prev);
    int yes=0;
    if(prev==-1 || v[i]>v[prev]) yes=1+lis(i+1,i);
    return dp[i][prev+1]=max(no,yes);
}

// ll LIS(ll n) // O(nlogn)
// {
//     vll temp; // this vector is not the LIS vector, but its size will give the length of LIS
//     temp.pb(a[0]);
//     for(int i=1;i<n;i++)
//     {
//         ll x=lower_bound(all(temp),a[i])-temp.begin();
//         if(x<temp.size()) temp[x]=a[i];
//         else temp.pb(a[i]);
//     }
//     return temp.size();
// }


int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<lis(0,-1)<<endl;
}




