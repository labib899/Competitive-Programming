#include<bits/stdc++.h>
using namespace std;

struct query
{
    int l,r,i;
};

const int N=2e5+5;
vector<int> g[N];
int c[N],color[N],in[N],out[N];
int ans[N],freq[N];
map<int,int> mp;
query qr[N];
int timer=0,block,cnt=0;
int n;

void compress()
{   
    int count=1;
    for(auto x:mp) mp[x.first]=count++;
    for(int i=0;i<n;i++) c[i]=mp[c[i]];
}

bool cmp(query a,query b)
{
    if(a.l/block!=b.l/block) return a.l/block < b.l/block;
    else return a.r < b.r;
}

void add(int idx)
{
    freq[color[idx]]++;
    if(freq[color[idx]]==1) cnt++;
}

void remove(int idx)
{
    freq[color[idx]]--;
    if(freq[color[idx]]==0) cnt--;
}

void dfs(int node,int p)
{
    in[node]=timer++;
    color[in[node]]=c[node];
    for(auto c:g[node])
    {
        if(c==p) continue;
        dfs(c,node);
    }
    out[node]=timer;
}

void solve()
{
    cin>>n;
    block=sqrt(n);
    for(int i=0;i<n;i++) 
    {
        cin>>c[i];
        mp[c[i]]=0;
    } 
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    compress();
    dfs(0,-1);
    for(int i=0;i<n;i++)
    {   
        int subsz=out[i]-in[i];
        int l=in[i],r=l+subsz-1;
        qr[i].l=l,qr[i].r=r,qr[i].i=i;
    }
    sort(qr,qr+n,cmp);
    int ml=0,mr=-1;
    for(int i=0;i<n;i++)
    {
        int l=qr[i].l,r=qr[i].r;

        while(ml>l) ml--,add(ml);
        while(mr<r) mr++,add(mr);
        while(ml<l) remove(ml),ml++;
        while(mr>r) remove(mr),mr--;

        ans[qr[i].i]=cnt;
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" "; cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1; //cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}