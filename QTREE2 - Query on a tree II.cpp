
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <limits>
using  namespace  std;

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
#define FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define Sort(x) sort(x.begin(),x.end())
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define ppr(a) cout<<a.x<<" "<<a.y<<"\n"
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define MAX 10002
#define EPS 1e-9

vi edge[MAX];
vi cost[MAX];
int par[18][MAX];
int dep[MAX];
int dis[MAX];
void DFS(int n,int depth,int prev,int dist)
{
    par[0][n]=prev;
    dep[n]=depth;
    dis[n]=dist;
    FOR(i,0,(int)edge[n].size()-1)
    {
        if(prev!=edge[n][i])
        {
            DFS(edge[n][i],depth+1,n,dist+cost[n][i]);
        }
    }
}
void LCA_pre(int n)
{
    for(int i=1;1<<i <=n;i++)
        FOR(j,1,n)
            if(par[i-1][j]!=-1)
                par[i][j]=par[i-1][par[i-1][j]];
}
int  LCA_query(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    int log=1;
    while((1<<(log+1))<=dep[u])log++;
    FORR(i,log,0)
        if(dep[u]-(1<<i)>=dep[v])u=par[i][u];
    if(u==v)return u;
    FORR(i,log,0)
        if(par[i][u]!=-1&&par[i][u]!=par[i][v])
            u=par[i][u],v=par[i][v];
    return par[0][u];
}
// 0-indexed
int kth_node(int u,int v,int w)
{
    int ances=LCA_query(u,v);
    int ances_dist=dep[u]-dep[ances];
    if(w>ances_dist)
    {
        w-=ances_dist;
        w=(dep[v]-dep[ances])-w;
        u=v;
    }
    FORR(i,17,0)
    if(w-(1<<i)>=0)u=par[i][u],w-=(1<<i);
    return u;
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n,u,v,w;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d",&n);
        FOR(i,1,n)
        {
            edge[i].clear();
            cost[i].clear();
            FOR(j,0,17)par[j][i]=-1;
        }
        FOR(i,1,n-1){
            scanf("%d%d%d",&u,&v,&w);
            edge[u].pb(v);
            edge[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        DFS(1,0,-1,0);
        LCA_pre(n);
        char comd[10];
        while(1)
        {
            getchar();
            scanf("%s",comd);
            if(comd[1]=='O')break;
            if(comd[0]=='D')
            {
                scanf("%d%d",&u,&v);
                int ans=dis[u]+dis[v] -2*dis[LCA_query(u,v)];
                printf("%d\n",ans);
            }
            else
            {
                scanf("%d%d%d",&u,&v,&w);w--;
                int ans=kth_node(u,v,w);
                printf("%d\n",ans);
            }
        }
        if(cs!=T)printf("\n");
    }
    return 0;
}

