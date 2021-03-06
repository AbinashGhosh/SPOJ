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

#define MAX 100007
#define EPS 1e-9

int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n,a,b,d,f;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d",&n);
        vpii s;
        FOR(i,0,n-1){
            scanf("%d%d",&a,&b);
            s.pb(mp(a,b));
        }
        scanf("%d%d",&d,&f);
        FOR(i,0,n-1)s[i].x=d-s[i].x;
        s.pb(mp(d,0));
        Sort(s);
        priority_queue<int>Q;
        int ans=0;
        bool aaa=true;
        FOR(i,0,n)
        {
            if(f<s[i].x)
            {
                while(f<s[i].x&&!Q.empty())
                {
                    f+=Q.top();
                    Q.pop();
                    ans++;
                }
                if(f<s[i].x)aaa=false;
            }
            Q.push(s[i].y);
        }
        if(aaa)printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}





