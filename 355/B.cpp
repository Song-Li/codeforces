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
#define LL long long
#define MIN(X,Y) (X)<(Y)?(X):(Y)
#define MAX(X,Y) (X)>(Y)?(X):(Y)
#define INFD 1e32
#define PI 3.14159265358979323
using namespace std;
int main(){
    long long n,h,k;
    long long now = 0,tmp;
    long long dd[111111];
    RII(n,h);
    RI(k);
    long long res = 0;
    for(int i = 0;i < n;++ i){
        RI(dd[i]);
    }
    int i = 0;
    while(1){
        while(i < n && now + dd[i] <= h)
            now += dd[i ++];
        if(now > k){
            res += now / k;
            now %= k;
        }else{
            now -= k;
            res ++;
        }
        if(now <= 0){
            if(i == n) break;
            now = 0;
        }
    }
    cout << res << endl;

    return 0;

}
