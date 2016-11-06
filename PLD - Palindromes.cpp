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

#define MAX 100007
#define EPS 1e-9

int  hasing(string s,string t,int n)
{
    int slen=s.size();
    int tlen=t.size();
    long long p = 999983;      // prime number
    long long M = 1000000009;  // prime number
    long long hs[slen],pw[tlen],h[tlen];
    // Power of P
    pw[0]=1;
    for(int i=1; i<tlen; i++)pw[i]=(pw[i-1]*p)%M;

    //find hash of s
    for(int i=0; i<slen; i++)
    {
        hs[i]=(((s[i]-'A'+1)*pw[i]))%M;
        if(i)hs[i]=(hs[i]+hs[i-1])%M;
    }
    //find hashs of t
    for(int i=0; i<tlen; i++)
    {
        h[i]=((t[i]-'A'+1)*pw[i])%M;
        if(i)h[i]=(h[i]+h[i-1])%M;
    }

    // Compare the hash
    //if(h[tlen-1]==hs[tlen-1])return -1;
    int ans=0;
    for(int i=0; i+n-1<tlen; i++)
    {
        long long curh=h[i+n-1];
        long long curhs=hs[tlen-1-i];
        if(i)curh=(curh-h[i-1]+M)%M;
        int j=tlen-1-i-n;
        //pr2(i,j);
        if(j!=-1)curhs=(curhs-hs[j]+M)%M;
        if(((curh*pw[j+1])%M)==((curhs*pw[i])%M))
            ans++;
    }
    return ans;
}
char tem[MAX];
int main()
{
    //READ("in.txt");

    string T,P;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        cin>>T;
        P=T;
        reverse(P.begin(),P.end());
        int  ans=hasing(P,T,n);
        //pr(ans);
        printf("%d\n",ans);
        //printf("Pattern Found %d\n",ans);
    }

    return 0;
}

