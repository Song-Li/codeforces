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
int start = 0;
int kind = 1;
int fir = 1;
int n,q;
void shift(int op){
    op = -op;
    if(op & 1){
        if(kind == 1) start += (op - 1) >> 1;
        else start += (op + 1) >> 1;
        kind = -kind;
    }else
        start += op >> 1;
    start = (start + n + n) % (n >> 1); 
}
int main(){
    RII(n,q);
    int op, num;
    for(int i = 0;i < q;++ i){
        RI(op);
        if(op == 1) {
            RI(op);
            shift(op);
        }else{
            fir = -fir;
        }
    }
    for(int i = 0;i < (n >> 1);++ i){
        if(kind == 1 && fir == 1) {
            printf("%d %d ", start * 2 + 1, start * 2 + 2);
        }else if(kind == 1 && fir == -1){
            printf("%d %d ", start * 2 + 2, start * 2 + 1);
        }else if(kind == -1 && fir == 1){
            printf("%d %d ",start * 2 + 2, (start * 2 + 3) % n);
        }else{
            printf("%d %d ",start * 2 + 1, (start * 2 + 4) % n == 0 ? n : (start * 2 + 4) % n);
        }
        start ++;
        start %= (n >> 1);
    }
    printf("\n");
    return 0;
}
