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
int main(){
    int n,k,a,b,c,d;
    RII(n,k);
    RII(a,b);
    RII(c,d);
    int ff = -1,ee = -1;
    if(n == 4) return 0 * printf("-1\n");
    if(k < n + 1) return 0 * printf("-1\n");
    printf("%d %d ",a,c);
    for(int i = 1;i <= n;++ i){
        if(i != a && i != b && i != c && i != d) {
            printf("%d ",i);
            if(ff == -1) ff = i;
            ee = i;
        }
    }
    printf("%d %d\n", d,b);
    printf("%d %d %d ", c, a, ff);
    for(int i = 1;i <= n;++ i){
        if(i != ff && i != ee && i != a && i != b && i != c && i != d) {
            printf("%d ",i);
        }
    }
    if(n == 5) printf("%d %d\n", b,d);
    else printf("%d %d %d\n", ee, b, d);

    return 0;
}
