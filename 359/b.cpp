#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <map>
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
int nums[128];
int getPos(int s, int p){
    for(int i = s;i < n;++ i)
        if(nums[i] == p) return i;
}

void swap(int s, int e){
    int tmp = nums[s];
    nums[s] = nums[e];
    nums[e] = tmp;
}
int main(){
    int pos;
    int num[128];
    RI(n);
    for(int i = 0;i < n;++ i){
        RI(nums[i]);
        num[i] = nums[i];
    }
    sort(num, num + n);
    for(int i = 0;i < n;++ i){
        pos = getPos(i, num[i]);
        if(pos == i) continue;
        for(int j = pos;j > i;-- j){
            printf("%d %d\n", j, j + 1);
            swap(j, j - 1);
        }
    }
    return 0;
}
