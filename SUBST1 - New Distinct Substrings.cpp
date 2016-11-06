/**************************************************
    _|||||_     -||||||||_    -|||    |||-   _|
   _||    ||_    |||    ||     |||    |||   |||
   |||    |||    |||    ||     |||    |||   |||
   |||    |||    |||___||-     |||____|||   |||
   ||||||||||    |||---||_     |||----|||   |||
   |||    |||    |||    ||     |||    |||   |||
   |||    |||    |||    ||     |||    |||   |||
  _|||    |||_  _||||||||-    _|||    |||_  |-
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

#define MAX 50007
#define EPS 1e-9

// Suffix Array O(n log n)
string text;
int Rank[MAX],tRank[MAX],lcp[MAX],c[MAX];
int arr[MAX];

void countingSort(int k,int n)
{
    int sum=0,mx = max(300, n);
    memset(c, 0, sizeof c);
    FOR(i,0,n-1) c[i+k<n?Rank[i+k]:0]++;
    FOR(i,0,128){
        int t = c[i];c[i] = sum;sum += t;
    }
    FOR(i,0,n-1) tRank[c[arr[i]+k <n?Rank[arr[i]+k]:0]++]=arr[i];
    FOR(i,0,n-1) arr[i] = tRank[i];
}
void buildSA(int n)
{
    int r,k;
    FOR(i,0,n-1) Rank[i]=text[i],arr[i] = i;
    for (k = 1; k < n; k <<= 1)
    {
        countingSort(k,n);
        countingSort(0,n);
        tRank[arr[0]] = r = 0;
        FOR(i,1,n-1)
        tRank[arr[i]]=(Rank[arr[i]]==Rank[arr[i-1]]&&Rank[arr[i]+k]==Rank[arr[i-1]+k])?r:++r;
        FOR(i,0,n-1)
        Rank[i] = tRank[i];
        if (Rank[arr[n-1]]==n-1) break;
    }
}
void kasai(string s)
{
    int n=s.size(),k=0,r;lcp[0]=0;
    FOR(i,0,n-1)
    {
        r=Rank[i];
        if(r==n-1) {k=0; continue;}
        int j=arr[r+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[r+1]=k?k--:0;
    }
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int n,T;
    char s[MAX];
    scanf("%d\n",&T);
    FOR(cs,1,T)
    {
        scanf("%s",s);
        text=s;
        text+="$";
        n=text.size();
        buildSA(n);
        kasai(text);

        ll sum=0;
        FOR(i,0,n-1)sum+=lcp[i]+1;
        printf("%lld\n",1ll*n*(n+1)/2-sum);
    }
    return 0;
}
