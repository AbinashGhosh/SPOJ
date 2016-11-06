//Abinash Ghosh
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
#define FOR(i, b, e) for(int i = b; i <=(int)(e); i++)
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

#define MAX 100007
#define EPS 1e-9
int a[MAX];
int b[MAX];
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int m,n;
    while(1)
    {
        scanf("%d",&n);if(n==0)break;
        FOR(i,0,n-1)scanf("%d",&a[i]);
        scanf("%d",&m);
        FOR(i,0,m-1)scanf("%d",&b[i]);
        vpii c;
        vi d(b,b+m);
        FOR(i,0,n-1)
        {

            vi::iterator it=lower_bound(d.begin(),d.end(),a[i]);
            if(it!=d.end()&&a[i]==*it)
            c.pb(mp(i,(int)(it-d.begin())));
        }
        c.pb(mp(n-1,m-1) );
        int j=0,k=0,ans=0;
        FOR(i,0,(int)c.size()-1)
        {
            int s1=0,s2=0;
            for(;j<=c[i].x;j++)s1+=a[j];
            for(;k<=c[i].y;k++)s2+=b[k];
            ans+=max(s1,s2);
        }
        d.clear();
        c.clear();
        printf("%d\n",ans);
    }
    return 0;
}



