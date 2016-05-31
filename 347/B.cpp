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
int n;
int main(){
    int pos = 0, neg = 0;
    int equ[1111111];
    int n, cnt = 0;
    char tmp;
    equ[cnt ++] = 1;
    pos = 1;
    while(1){
        scanf("%c",&tmp);
        if(tmp == '+'){
            equ[cnt ++] = 1;
            pos ++;
        }else if(tmp == '-'){
            equ[cnt ++] = -1;
            neg ++;
        }else if(tmp == '='){
            RI(n);
            break;
        }
    }

    if(pos * n - neg < n || pos - neg * n > n) return 0 * printf("Impossible\n");
    printf("Possible\n");
    int total = 0;
    if(pos > neg){
        total = neg * n + n;
        int avg = total / pos;
        int rr = total % pos;
        for(int i = 0;i < cnt;++ i){
            if(equ[i] == 1){
                if(i) printf(" + ");
                if(rr > 0){
                    if(rr + avg > n){
                        rr -= n - avg;
                        printf("%d", n);
                    }else{
                        printf("%d", rr + avg);
                        rr = 0;
                    }
                }else printf("%d", avg);
            }else printf(" - %d", n);
        }
        printf(" = %d\n", n);
    }else if(pos <= neg){
        total = pos * n - n;
        int avg = total / neg;
        int rr = total % neg;
        for(int i = 0;i < cnt;++ i){
            if(equ[i] == -1){
                printf(" - ");
                if(rr > 0){
                    if(rr + avg > n){
                        rr -= n - avg;
                        printf("%d", n);
                    }else{
                        printf("%d", rr + avg);
                        rr = 0;
                    }
                }else printf("%d", avg);
            }else 
                if(i) printf(" + %d", n);
                else printf("%d",n);

        }
        printf(" = %d\n", n);
    }

    return 0;

}
