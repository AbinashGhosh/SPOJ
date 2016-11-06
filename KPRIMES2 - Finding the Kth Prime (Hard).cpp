#include<cstdio>
#include<ctime>
#include<vector>
#define M 500000007
using namespace std;
bool marked[M];
void sieve(long long n)
{
    marked[1]=true;
    for (long long i=3;i*i<=n;i+=2)
        if (marked[i]==false)   // i is a prime
            for(long long j=i*i,k=i<<1;j<=n;j+=k)
                marked[j]=true;
    //for (long long i=4;i<=n;i+=2) marked[j]=true;
}
bool isPrime(long long n)
{
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    return marked[n] == false;
}

/**
// Prime Genarator

bool mark[10005];
int prime[10005];
int  prime_gen(int n)
{
    for(int i=3;i*i<=n;i+=2)
        if(!mark[i])
            for(int j=i*i,k=i<<1;j<=n;j+=k)
            mark[j]=true;
    int k=0;
    prime[k++]=2;
    for(int i=3;i<=n;i+=2)if(!mark[i])prime[k++]=i;
    return k;
}

*/
// linear time sieve
const int N = 10000000 ;
int lp [ N + 1 ] ;
vector < int > pr ;
void linearSieve()
{
    for ( int i = 2 ; i <= N ; ++ i )
    {
        if ( lp [ i ] == 0 )
        {
            lp [ i ] = i ;
            pr. push_back ( i ) ;
        }
        for ( int j = 0 ; j < ( int ) pr. size ( ) && pr [ j ] <= lp [ i ] && i * pr [ j ] <= N ; ++ j )
            lp [ i * pr [ j ] ] = pr [ j ] ;
    }
}
int prime[M];
int main()
{

      linearSieve();
//      sieve(50000001);
//      long long c=0;
//      for(int i=1;i<=50000001;i++)if(isPrime(i))prime[c++]=i;


      int T,n;
      scanf("%d",&T);
      for(int i=1;i<=T;i++)
      {
          scanf("%d",&n);
          printf("%d\n",pr[n-1]);
      }

    return 0;
}
//      cl = clock() - cl;
//    printf("Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);
