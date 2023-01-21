#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi v;

int maxSum(vi &v)
{
    int n=v.size();
    int maxi=INT_MIN,sum=0;
    for(int i=0;i<n;i++)
    {
        sum=max(v[i],sum+v[i]);
        maxi=max(maxi,sum);
    }
    return maxi;
}

int main()
{
    int n;cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<maxSum(v)<<endl;
}
