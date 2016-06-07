#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <set>
#include <unordered_set>
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

int main(){
    int n,x,y,nx,ny, res = 0;
    int pos = 1;
    RI(n);
    for(int i = 0;i <= n;++ i){
        RII(nx,ny);
        if(i > 1){
            if(nx == x){
                if(ny > y) res += pos, pos = 1;
                else res += !pos, pos = 0;
            }else {
                if(nx > x) res += !pos, pos = 1;
                else res += pos, pos = 0;
            }
        }
        x = nx;
        y = ny;
    }
    cout << res << endl;
    return 0;
}
