#include<iostream>
using namespace std;
long long I=10000000,N;
int f(int n,int x){
//    if(a[n]>x) {  }
//    if(a[n]!=-1) return a[n];
//    if(n==N || n>N) { return 0 ; a[n]=x; }
//    f(n*3,x+1);
//    f(n*2,x+1);
//    f(n+1,x+1);
//    /*
    int i=x;
    if(n==1) { if(I>i) { I=i;}   return 0; }
    i=x+1;
    if(n%3==0) f(n/3,i);
    if(n%2==0) f(n/2,i);
    f(n-1,i);
}
int main(){
    int n;
    while(1){
    I=10000000;
    cin>>N;
    //int a[100]; for(int i=0;i<=100;i++) a[i]=-1;
    f(N,0);
    cout<<I<<"\n";
    }
    return 0;
}
