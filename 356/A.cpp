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
#define PI 3.14159265358979323
using namespace std;
int main(){
    int num[110];
    int in[6];
    int res = 1000000000, sum = 0;
    memset(num,0,sizeof(num));
    for(int i = 0;i < 5;++ i){
        RI(in[i]);
        sum += in[i];
        num[in[i]] ++;
    }
    res = sum;
    for(int i = 0;i < 5;++ i){
        if(num[in[i]] == 2){
            res = MIN(sum - in[i] * 2, res);
            in[i] = -1;
        }else if(num[in[i]] >= 3){
            res = MIN(sum - in[i] * 3, res);
            in[i] = -1;
        }
    }
    cout << res << endl;
    return 0;
}
