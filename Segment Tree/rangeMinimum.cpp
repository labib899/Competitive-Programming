#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
#define fastIO ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define forn(j,n,x) for(ll i=j;i<n;i+=x)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


void solve();
const int N=1e5+10;
vi v(N),seg(4*N);
void segment(int si,int ss,int se);
int query(int si,int ss,int se,int qs,int qe);

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    fastIO;
    ll t=1; //cin>>t;
    while(t--) solve();
}

void solve()
{
    int n; cin>>n;
    forn(1,n+1,1) cin>>v[i];
    segment(1,1,n);
    int q; cin>>q;
    while(q--)
    {
        int l,r; cin>>l>>r;
        cout<<query(1,1,n,l+1,r+1)<<endl;
    }
}

void segment(int si,int ss,int se)
{
    if(ss==se)
    {
        seg[si]=v[ss];
        return;
    }
    int mid=(ss+se)/2;
    segment(2*si,ss,mid);
    segment(2*si+1,mid+1,se);
    seg[si]=min(seg[2*si],seg[2*si+1]);
}

int query(int si,int ss,int se,int qs,int qe)
{
    if(ss>qe || se<qs) return INT_MAX;
    if(ss>=qs && se<=qe) return seg[si];
    int mid=(ss+se)/2;
    int l=query(2*si,ss,mid,qs,qe);
    int r=query(2*si+1,mid+1,se,qs,qe);
    return min(l,r);
}
