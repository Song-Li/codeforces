#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#define PII pair<int, int>
#define MP make_pair
#define RI(X) scanf("%d", &(X))
#define RII(X,Y) scanf("%d %d", &(X), &(Y))
using namespace std;
int max(int a,int b){
    return a > b ? a : b;
}
int min(int a,int b){
    return a < b ? a : b;
}
int dd[111];
int main(){
    int n;
    int res = -1;
    RI(n);
    dd[0] = 0;
    for(int i = 1;i <= n;++ i){
        RI(dd[i]);
        if(dd[i] - dd[i - 1] > 15){
            res = dd[i - 1] + 15;
            break;
        }
    }
    if(res == -1) res = dd[n] + 15;
    res = min(res, 90);
    printf("%d\n",res);
    return 0;
}
