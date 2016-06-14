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
    LL n;
    RL(n);
    const int a = 1234567, b = 123456, c = 1234;
    LL na, nb, nc;
    na = n / a;
    LL lasta, lastb;
    for(int i = 0;i <= na;++ i){
        lasta = n - i * a;
        nb = lasta / b;
        for(int j = 0;j <= nb;++ j){
            lastb = lasta - j * b;
            if(lastb % c == 0) return 0 * printf("YES\n");
        }
    }
    printf("NO\n");
    return 0;

}
