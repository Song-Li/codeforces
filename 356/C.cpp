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
int pri[100] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int main(){
    string ans;
    int res = 0;
    for(int i = 0;i < 15;++ i){
        cout << pri[i] << endl;
        fflush(stdout);
        cin >> ans;
        if(ans == "yes") {
            if(pri[i] * pri[i] < 100) {
                cout << pri[i] * pri[i] << endl;
                fflush(stdout);
                cin >> ans;
                if(ans == "yes")
                    res ++;
            }
            res ++;
        }
        if(res >= 2) {
            printf("composite\n");
            fflush(stdout);
            return 0;
        }
    }
    
    printf("prime\n");
    fflush(stdout);
    return 0;
}
