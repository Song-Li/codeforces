#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <set>
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
void swap(int *t1, int *t2){
    int tmp;
    tmp = *t1;
    *t1 = *t2;
    *t2 = tmp;
}
int main(){
    int n, m, min1, max2;
    int t1,t2;
    int res = -1;
    RII(n,m);
    set<int> div1,div2;
    for(int i = 0;i < m;++ i){
        RII(t1,t2);
        if(t1 < t2) swap(t1,t2);
        if(div1.find(t2) != div1.end() || div2.find(t1) != div2.end()) {
            res = 0;
        }else{
            div1.insert(t1);
            div2.insert(t2);
        }
    }
    if(m && *div1.begin() < *(-- div2.end())) res = 0;
    if(res == 0) return 0 * printf("0\n");
    if(m) printf("%d\n", *div1.begin() - *(-- div2.end()));
    else printf("%d\n", n - 1);
    return 0;
}
