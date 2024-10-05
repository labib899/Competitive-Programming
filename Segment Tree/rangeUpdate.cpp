#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+10;
vector<int> arr(N),seg(4*N),lazy(4*N);

// build(index of root,low,high), O(n)
void build(int ind,int low,int high)
{   
    if(low==high) { seg[ind]=arr[low]; return; }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid);  
    build(2*ind+2,mid+1,high); 
    seg[ind]=seg[2*ind+1]+seg[2*ind+2]; 
}

// O(logn)
int query(int ind,int low,int high,int l,int r)
{   
    if(lazy[ind])  // pending updates
    {
        seg[ind]+=lazy[ind]*(high-low+1);
        if(low!=high) lazy[2*ind+1]+=lazy[ind], lazy[2*ind+2]+=lazy[ind]; // if children exist
        lazy[ind]=0;
    }
    if(l<=low and high<=r) return seg[ind];  
    if(high<l or low>r) return 0;  
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);  
    int right=query(2*ind+2,mid+1,high,l,r);  
    return left+right;
}

// O(logn)
void update(int ind,int low,int high,int l,int r,int val)
{
    if(lazy[ind])  // pending updates
    {
        seg[ind]+=lazy[ind]*(high-low+1);
        if(low!=high) lazy[2*ind+1]+=lazy[ind], lazy[2*ind+2]+=lazy[ind]; // if children exist
        lazy[ind]=0;
    }
    if(l<=low and high<=r)  
    {
        seg[ind]+=val*(high-low+1);
        if(low!=high) lazy[2*ind+1]+=val, lazy[2*ind+2]+=val;
        return;
    }
    if(high<l or low>r) return; 
    int mid=(low+high)/2;
    update(2*ind+1,low,mid,l,r,val);
    update(2*ind+2,mid+1,high,l,r,val);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}


void solve()
{
    int n,q; cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    build(0,0,n-1);
    while(q--)
    {
        int type; cin>>type;
        if(type==1)
        {
            int a,b,u; cin>>a>>b>>u;
            a--,b--;
            update(0,0,n-1,a,b,u);
        }
        else 
        {
            int k; cin>>k;
            k--;
            cout<<query(0,0,n-1,k,k)<<endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}
 