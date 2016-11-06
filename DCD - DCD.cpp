/**************************************************
    _¦¦¦¦¦¦_    ¯¦¦¦¦¦¦¦¦_    ¯¦¦¦    ¦¦¦¯   _¦
   _¦¦    ¦¦_    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦___¦¦¯     ¦¦¦____¦¦¦   ¦¦¦
   ¦¦¦¦¦¦¦¦¦¦    ¦¦¦¯¯¯¦¦_     ¦¦¦¯¯¯¯¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
  _¦¦¦    ¦¦¦_  _¦¦¦¦¦¦¦¦¯    _¦¦¦    ¦¦¦_  ¦¯
***************************************************/
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

#define MAX 131100
#define EPS 1e-9
ll p[20];
ll d[20];
ll w[MAX];
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        FOR(i,0,n-1)scanf("%lld",&p[i]);
        FOR(i,n,n+m-1)scanf("%lld",&p[i]);
        vl ans;
        for(int i=0;i<((1<<(n+m)));i++)
        {
            ll sum=0;
            //pr(i);
            FOR(j,0,n+m-1)
            {
                if((i&(1<<j))!=0)
                {
                    if(j>=n)sum-=p[j];
                    else sum+=p[j];

                }
            }
            ans.pb(sum);
        }
        Sort(ans);
        ll dif;
        scanf("%lld",&dif);
        ll mx=0,lo=0,hi=0;
        FOR(i,0,(int)ans.size()-1)
        {
            ll l=ans[i];
            ll r=l+dif-1;
            ll sol=upper_bound(ans.begin()+i,ans.end(),r)-ans.begin();
            sol-=i;
            if(mx<sol)
            {
                lo=l;hi=r;
                mx=sol;
            }
        }
        printf("%lld %lld %lld\n",lo,hi,mx);
    }

    return 0;
}

