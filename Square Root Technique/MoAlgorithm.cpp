#include <bits/stdc++.h>
using namespace std;

struct query
{
    int l,r,i;
};

const int N=1e6+5;
int arr[N],ans[N],freq[N];
query qr[N];
int block,cnt=0;

bool cmp(query a,query b)
{
    if(a.l/block!=b.l/block) return a.l/block < b.l/block;
    else return a.r < b.r;
}

void add(int idx)
{
    freq[arr[idx]]++;
    if(freq[arr[idx]]==1) cnt++;
}

void remove(int idx)
{
    freq[arr[idx]]--;
    if(freq[arr[idx]]==0) cnt--;
}

void solve()
{
    int n; cin>>n;
    block=sqrt(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int q; cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r; cin>>l>>r;
        l--,r--;
        qr[i].l=l, qr[i].r=r, qr[i].i=i;
    }

    sort(qr,qr+q,cmp);
    int ml=0,mr=-1;
    for(int i=0;i<q;i++)
    {
        int l=qr[i].l, r=qr[i].r;

        while(ml>l) ml--,add(ml);
        while(mr<r) mr++,add(mr);
        while(ml<l) remove(ml),ml++;
        while(mr>r) remove(mr),mr--;

        ans[qr[i].i]=cnt;
    }   
    for(int i=0;i<q;i++) cout<<ans[i]<<" "<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1; //cin>>t;
    while(t--) solve();
}