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

int n,m,q;
int op[11111][4];
int mat[111][111];
void output(){
    for(int i = 0;i < n;++ i, printf("\n"))
        for(int j = 0;j < m;++ j)
            printf("%d ", mat[i][j]);
}
void shift(int type, int id){
    if(type == 1){
        int tmp = mat[id][m - 1];
        for(int i = m - 1;i > 0;-- i){
            mat[id][i] = mat[id][i - 1];
        }
        mat[id][0] = tmp;
    }else{
        int tmp = mat[n - 1][id];
        for(int i = n - 1;i > 0;-- i)
            mat[i][id] = mat[i - 1][id];
        mat[0][id] = tmp;
    }
}
int main(){
    RIII(n,m,q);
    memset(mat, 0, sizeof(mat));
    for(int i = 0;i < q;++ i){
        RI(op[i][0]);
        if(op[i][0] == 3)
            RIII(op[i][1], op[i][2], op[i][3]);
        else
            RI(op[i][1]);
    }
    for(int i = q - 1;i >= 0;-- i){
        if(op[i][0] == 3){
            mat[op[i][1] - 1][op[i][2] - 1] = op[i][3];
        }
        else 
            shift(op[i][0], op[i][1] - 1);
    }
    output();
    return 0;
}
