#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+10;
vector<int> arr(N),seg(4*N),lazy(4*N);

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
    if(lazy[idx])  // pending increment updates
    {
        seg[idx]+=lazy[idx]*(high-low+1);
        if(low!=high) // if children exist
        {
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx]; 
        }
        lazy[idx]=0;
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
void update(int idx,int low,int high,int l,int r,int val)
{
    propagate(idx,low,high);
    if(l<=low and high<=r)  
    {
        lazy[idx]+=val;
        propagate(idx,low,high);
        return;
    }
    if(high<l or low>r) return; 
    int mid=(low+high)/2;
    update(2*idx+1,low,mid,l,r,val);
    update(2*idx+2,mid+1,high,l,r,val);
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
 