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

#define MAX 10000007
#define EPS 1e-9

struct rec{
    int lim,x,y,val,pr;
}box[2*50000+100000+10];
bool cmp(rec a,rec b){
    if(a.x==b.x)return a.pr<b.pr;
    return a.x<b.x;
}
int tree[10000007];
int query(int idx)
{
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx&(-idx);
    }
    return sum;
}
void update(int idx,int x,int n)
{
    while(idx<=n){
        tree[idx]+=x;
        idx+=idx&(-idx);
    }
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int n,T,r;
    int ans[50005];
    scanf("%d",&T);
    FOR(t,1,T)
    {
        mem(tree,0);
        mem(ans,0);
        scanf("%d",&n);
        int a=n;
        FOR(i,0,n-1)
        {
            scanf("%d%d%d",&box[i].x,&box[i].y,&box[i].val);
            box[i].x++,box[i].y++,box[i].pr=2;
        }
        scanf("%d",&r);
        FOR(i,1,r)
        {
            scanf("%d%d",&box[a].x,&box[a].y);
            box[a].x++,box[a].y++,box[a].pr=1,box[a].val=i;
            a++;
            scanf("%d%d",&box[a].x,&box[a].y);
            box[a].x++,box[a].y++,box[a].pr=3,box[a].val=i;
            box[a-1].lim=box[a].y;
            box[a].lim=box[a-1].y;
            a++;
        }
        sort(box,box+a,cmp);

        FOR(i,0,a-1)
        {
            if(box[i].pr==2)update(box[i].y,box[i].val,10000000);
            else if(box[i].pr==1)ans[box[i].val]-=(query(box[i].lim)-query(box[i].y-1));
            else ans[box[i].val]+=(query(box[i].y)-query(box[i].lim-1));
        }
        FOR(i,1,r)
        printf("%d\n",ans[i]);

    }
    return 0;
}




