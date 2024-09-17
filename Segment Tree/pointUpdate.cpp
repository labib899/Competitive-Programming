#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+10;
vector<int> arr(N),seg(4*N);

// build(index of root,low,high)
void build(int ind,int low,int high)
{   
    if(low==high) { seg[ind]=arr[low]; return; }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid);  // build left tree
    build(2*ind+2,mid+1,high);  // build right tree
    seg[ind]=seg[2*ind+1]+seg[2*ind+2]; // sum
}

int query(int ind,int low,int high,int l,int r)
{
    if(l<=low and high<=r) return seg[ind];  // completely inside the query
    if(high<l or low>r) return 0;  // completely outside of the query
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);  // left tree
    int right=query(2*ind+2,mid+1,high,l,r);  // right tree
    return left+right;
}

// O(logn)
void update(int ind,int low,int high,int i,int val)
{
    if(low==high) { seg[ind]=val; return; }  // low=high=i
    int mid=(low+high)/2;
    if(i<=mid) update(2*ind+1,low,mid,i,val);  // update left side
    else update(2*ind+2,mid+1,high,i,val);  // update right side
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
            int k,u; cin>>k>>u;
            k--;
            update(0,0,n-1,k,u);
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
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}
