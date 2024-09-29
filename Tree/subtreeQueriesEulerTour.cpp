#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,q,timer=1;
vector<vector<int>> g;
vector<int> in,val,sub,seg,vec;

void dfs(int node,int p)
{
    in[node]=timer++;
    val[in[node]]=vec[node];
    for(auto c:g[node])
    {
        if(c!=p) 
        {
            dfs(c,node);
            sub[node]+=sub[c];
        }
    }
}

void build(int ind,int low,int high)
{   
    if(low==high) { seg[ind]=val[low]; return; }
    int mid=(low+high)/2;
    build(2*ind,low,mid);
    build(2*ind+1,mid+1,high);  
    seg[ind]=seg[2*ind]+seg[2*ind+1]; 
}

int query(int ind,int low,int high,int l,int r)
{
    if(l<=low and high<=r) return seg[ind];  
    if(high<l or low>r) return 0;  
    int mid=(low+high)/2;
    int left=query(2*ind,low,mid,l,r);  
    int right=query(2*ind+1,mid+1,high,l,r); 
    return left+right;
}

void update(int ind,int low,int high,int i,int value)
{
    if(low==high) { seg[ind]=value; return; } 
    int mid=(low+high)/2;
    if(i<=mid) update(2*ind,low,mid,i,value); 
    else update(2*ind+1,mid+1,high,i,value); 
    seg[ind]=seg[2*ind]+seg[2*ind+1];
}

void solve()
{
    cin>>n>>q;
    g.resize(n+1); seg.resize(4*n,0); val.resize(n+1); 
    sub.resize(n+1,1); in.resize(n+1); vec.resize(n+1);
    for(int i=1;i<=n;i++) cin>>vec[i];
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1);
    build(1,1,n);
    while(q--)
    {
        int type; cin>>type;
        if(type==1)
        {
            int s,x; cin>>s>>x; 
            update(1,1,n,in[s],x);
            val[in[s]]=x;
        }
        else 
        {
            int s; cin>>s;
            cout<<query(1,1,n,in[s],in[s]+sub[s]-1)<<endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1; //cin>>t;
    while(t--) solve();
}