#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <set>
#include <map>
#define PII pair<int, int>
#define PFF pair<float, float>
#define PDD pair<double, double>
#define MP make_pair
#define RI(X) scanf("%d", &(X))
#define RII(X,Y) scanf("%d %d", &(X), &(Y))
#define RIII(X,Y,Z) scanf("%d %d %d", &(X), &(Y),&(Z))
#define RD(X) scanf("%lf", &(X))
#define RDD(X,Y) scanf("%lf %lf", &(X), &(Y))
#define RF(X) scanf("%f", &(X))
#define RFF(X,Y) scanf("%f %f", &(X), &(Y))
#define RL(X) scanf("%I64d", &(X))
#define RLL(X,Y) scanf("%I64d %I64d", &(X), &(Y))
#define LL __int64
#define MIN(X,Y) (X)<(Y)?(X):(Y)
#define INFD 1e32
using namespace std;
int convert(char c){
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if(c >= 'a' && c <= 'z') return c - 'a' + 36;
    if(c == '-') return 62;
    if(c == '_') return 63;
}
int fits[6] = {32,16,8,4,2,1};
int getZero(int num){
    int res = 0;
    int last = 0;
    int i = 0;
    while(1){
        last = num - fits[i];
        if(last >= 0) num = last;
        else if(last < 0) res ++;
        i ++;
        if(i == 6) break;
    }
    return res;
}
long long modexp(long long a,long long b,long long n)     
{     
    long long ret=1;     
    long long tmp=a;     
    while(b){     
        if(b&0x1) ret=ret*tmp%n;     
        tmp=tmp*tmp%n;     
        b>>=1;     
    }     
    return ret % n;     
} 
int main(){
    long long res = 0;
    string ss;
    cin >> ss;
    int tmp;
    for(int i = 0;i < ss.length();++ i){
        tmp = convert(ss[i]);
        res += getZero(tmp);
    }
    res = modexp(3,res,1000000007);
    printf("%I64d\n",res);
    return 0;
}
