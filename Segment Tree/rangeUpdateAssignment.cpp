#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+10;
vector<int> arr(N),seg(4*N),lazy_add(4*N),lazy_assign(4*N,-1);

// O(n)
void build(int idx,int low,int high)
{   
    if(low==high) { seg[idx]=arr[low]; return; }
    int mid=(low+high)/2;
    build(2*idx+1,low,mid);  
    build(2*idx+2,mid+1,high); 
    seg[idx]=seg[2*idx+1]+seg[2*idx+2]; 
}

void propagate(int idx,int low,int high)
{   
    if(lazy_assign[idx]!=-1) // pending assignment updates
    {
        seg[idx]=lazy_assign[idx]*(high-low+1);
        if(low!=high) // if children exist
        {
            lazy_assign[2*idx+1]=lazy_assign[idx];
            lazy_assign[2*idx+2]=lazy_assign[idx];
            lazy_add[2*idx+1]=lazy_add[2*idx+2]=0; // cancel pending addition
        }
        lazy_assign[idx]=-1;
    }

    if(lazy_add[idx])  // pending increment updates
    {
        seg[idx]+=lazy_add[idx]*(high-low+1);
        if(low!=high) // if children exist
        {
            lazy_add[2*idx+1]+=lazy_add[idx];
            lazy_add[2*idx+2]+=lazy_add[idx]; 
        }
        lazy_add[idx]=0;
    }
}

// O(logn)
int query(int idx,int low,int high,int l,int r)
{   
    propagate(idx,low,high);
    if(l<=low and high<=r) return seg[idx];  
    if(high<l or low>r) return 0;  
    int mid=(low+high)/2;
    int left=query(2*idx+1,low,mid,l,r);  
    int right=query(2*idx+2,mid+1,high,l,r);  
    return left+right;
}

// O(logn)
void update_add(int idx,int low,int high,int l,int r,int val)
{
    propagate(idx,low,high);
    if(l<=low and high<=r)  
    {
        lazy_add[idx]+=val;
        propagate(idx,low,high);
        return;
    }
    if(high<l or low>r) return; 
    int mid=(low+high)/2;
    update_add(2*idx+1,low,mid,l,r,val);
    update_add(2*idx+2,mid+1,high,l,r,val);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
}

void update_assign(int idx,int low,int high,int l,int r,int val)
{
    propagate(idx,low,high);
    if(l<=low and high<=r)  
    {
        lazy_assign[idx]=val;
        lazy_add[idx]=0;
        propagate(idx,low,high);
        return;
    }
    if(high<l or low>r) return; 
    int mid=(low+high)/2;
    update_assign(2*idx+1,low,mid,l,r,val);
    update_assign(2*idx+2,mid+1,high,l,r,val);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
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
            int a,b,x; cin>>a>>b>>x;
            a--,b--;
            update_add(0,0,n-1,a,b,x);
        }
        else if(type==2)
        {
            int a,b,x; cin>>a>>b>>x;
            a--,b--;
            update_assign(0,0,n-1,a,b,x);
        }
        else 
        {
            int a,b; cin>>a>>b;
            a--,b--;
            cout<<query(0,0,n-1,a,b)<<endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}