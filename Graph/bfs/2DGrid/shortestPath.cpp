#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n,m,srcX,srcY;
vector<vector<char>> g,dir;
vector<vector<int>> vis,dist;
vector<int> dx={-1,0,1,0}, dy={0,1,0,-1};
string d="URDL", path;

bool isValid(int x,int y)
{
    if(x<0 or x>=n or y<0 or y>=m) return false;
    if(vis[x][y]==1 or g[x][y]=='#') return false;
    return true;
}

bool bfs(int x,int y)
{
    queue<pii> q;
    q.push({x,y});
    vis[x][y]=1;

    while(q.size())
    {
        int px=q.front().first,py=q.front().second;
        q.pop();

        if(g[px][py]=='B')
        {
            while(1)
            {
                path.push_back(dir[px][py]);
                if(path.back()=='U') px++;
                else if(path.back()=='D') px--;
                else if(path.back()=='R') py--;
                else if(path.back()=='L') py++;

                if(px==x and py==y) break;
            }
            reverse(path.begin(),path.end());
            return true;
        }

        for(int i=0;i<4;i++)
        {
            if(isValid(px+dx[i],py+dy[i]))
            {
                int newX=px+dx[i],newY=py+dy[i];
                q.push({newX,newY});
                vis[newX][newY]=1;
                dir[newX][newY]=d[i];
                //dist[newX][newY]=dist[px][py]+1;
            }
        }
    }
    return false;
}

void solve()
{
    cin>>n>>m;
    g.resize(n,vector<char>(m));
    vis.resize(n,vector<int>(m,0));
    dir.resize(n,vector<char>(m));
    //dist.resize(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='A') srcX=i,srcY=j;
        }
    }
    if(bfs(srcX,srcY)) cout<<"YES"<<endl<<path.size()<<endl<<path<<endl;
    else cout<<"NO"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}