//Abinash Ghosh
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
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
using  namespace  std;

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
#define FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
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

#define MAX 80007
#define EPS 1e-9
int num[10000007],tree[MAX*10];
int arr[10*MAX];
void query(int node,int b,int e)
{
    if(tree[node]>=0){
        arr[tree[node]]=1;
        return;
    }
    if(b==e)return;
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    query(left,b,mid);
    query(right,mid+1,e);
}
void update(int node,int b,int e,int i,int j,int newv,int par=-1)
{
    if(par!=-1)tree[node]=par;
    if(e<i||b>j)return;
    if(b>=i&&e<=j)
    {
        tree[node]=newv;
        return;
    }
    if(b==e)return;
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,newv,tree[node]);
    update(right,mid+1,e,i,j,newv,tree[node]);
    tree[node]=-1;
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n;
    pii p[40007];
    set<int >s;

    scanf("%d",&T);
    FOR(t,1,T)
    {
        mem(tree,-1);
        mem(arr,0);
        s.clear();
        scanf("%d",&n);
        FOR(i,0,n-1)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            s.insert(p[i].x);
            s.insert(p[i].y);
        }
        int idx=1;
        FORI(it,s)
            num[*it]=idx++;
        int ans=0;
        FOR(i,0,n-1)
            update(1,1,idx-1,num[p[i].x],num[p[i].y],i);
        query(1,1,idx-1);
        FOR(i,0,n-1)if(arr[i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}




