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
int cs[5555],res[5555], numc[5555];
int main(){
    int n,tmp;
    int maxt = -1, minc = 10000;
    RI(n);
    memset(res,0,sizeof(res));
    for(int i = 0;i < n;++ i)
        RI(cs[i]);
    for(int i = 0;i < n;++ i){
        memset(numc, 0, sizeof(numc));
        maxt = -1;
        minc = 10000;
        for(int j = i;j < n;++ j){
            tmp = ++ numc[cs[j]];
            if(tmp > maxt){
                maxt = tmp;
                minc = cs[j];
            }else if(tmp == maxt){
                if(cs[j] < minc) minc = cs[j];
            }
            res[minc] ++;
            
        }
    }
    for(int i = 1;i <= n;++ i)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
