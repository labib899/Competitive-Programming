#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int arr[N],seg[4*N];

// build(index of root,low,high)
void build(int ind,int low,int high)
{   
    if(low==high) 
    {
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid); // build left tree
    build(2*ind+2,mid+1,high); // build right tree
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]); // max for storing maximum value, min for minimum value
}

int query(int ind,int low,int high,int l,int r)
{
    if(l<=low && high<=r) return seg[ind]; // completely inside the query
    if(high<l || low>r) return INT_MIN; // completely outside of the query
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r); // left tree
    int right=query(2*ind+2,mid+1,high,l,r); // right tree
    return max(left,right);
}

void solve()
{
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    build(0,0,n-1); 
    int q; cin>>q;
    while(q--)
    {
        int l,r; cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
}


int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}

