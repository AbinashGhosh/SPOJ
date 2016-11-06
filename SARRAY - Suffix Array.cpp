//OM
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <sstream>
#include <algorithm>
using  namespace  std;

#define  x first
#define  y second
#define  pb push_back
#define  mp make_pair
#define  PI (acos(-1.0))
#define  mem(a,b) memset(a,b,sizeof(a))
#define  Sort(x) sort(x.begin(),x.end())
#define  FOR(i, b, e) for(int i = b; i <= e; ++i)
#define  FORR(i, b, e) for(int i = b; i >= e; i--)
#define  FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define  pr(x) cout<<x<<"\n"
#define  prs(x) cout<<x<<" "
#define  pr2(x,y) cout<<x<<" "<<y<<"\n"
#define  pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define  ppr(a) cout<<a.x<<" "<<a.y<<"\n"

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  vector <int> vi;
typedef  vector <pii> vpii;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

#define  EPS 1e-9
#define  MAX 100007

// Suffix Array O(n log n) from CP3
string text;
int Rank[MAX],tRank[MAX],lcp[MAX],c[MAX];
int arr[MAX];

void countingSort(int k,int n,int r)
{
    int sum=0,mx = max(300, r+1);
    memset(c, 0, sizeof c);
    FOR(i,0,n-1) c[i+k<n?Rank[i+k]:0]++;
    FOR(i,0,mx){
        int t = c[i];c[i] = sum;sum += t;
    }
    FOR(i,0,n-1) tRank[c[arr[i]+k <n?Rank[arr[i]+k]:0]++]=arr[i];
    FOR(i,0,n-1) arr[i] = tRank[i];
}
void buildSA(int n)
{
    int r=300,k;
    FOR(i,0,n-1) Rank[i]=text[i],arr[i] = i;
    for (k = 1; k < n; k <<= 1)
    {
        countingSort(k,n,r);
        countingSort(0,n,r);
        tRank[arr[0]] = r = 0;
        FOR(i,1,n-1)
        tRank[arr[i]]=(Rank[arr[i]]==Rank[arr[i-1]]&&Rank[arr[i]+k]==Rank[arr[i-1]+k])?r:++r;
        FOR(i,0,n-1)Rank[i] = tRank[i];
        if (Rank[arr[n-1]]==n-1) break;
    }
}
void printSA()
{
    cout << "Suffix Array : \n\n";
    for(int i = 0; i <(int)text.size(); i++)
        cout<<arr[i]<<' '<<lcp[i]<<' '<<text.substr(arr[i])<<endl;
}
int main()
{
    int T,n;
    char s[MAX];
    scanf("%s",s);
    text=s;
    text+="$";
    n=text.size();
    buildSA(n);
    FOR(i,1,n-1)printf("%d\n",arr[i]);
    //printSA();

    return 0;
}
