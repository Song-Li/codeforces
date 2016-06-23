//not finished@!!!!!!!!!!!!!!!!!!!!!
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
int d1[32], d2[32];
int n,m;
int len1, len2;
void getD(){
    int pos = 0;
    while(n){
        d1[pos ++] = n % 7;
        n /= 7;
    }
    len1 = pos - 1;
    pos = 0;
    while(m){
        d2[pos ++] = m % 7;
        m /= 7;
    }
    len2 = pos - 1;
}
LL aa(int l1, int l2, set<int> oc){
    return yn(l1, l2, oc) + ny(l1, l2, oc) + nn(l1, l2, oc) + yy(l1, l2, oc);
}

int getocn(int number, set<int> oc){
    int ret = 0;
    for(int i = 0;i <= number;++ i){
        if(oc.find(i) != oc.end())
            ret ++;
    }
    return ret;
}

LL nn(int l1, int l2, set<int> oc){
    LL tmp;
    if(d1[l1] < d2[l2]){
        tmp = getocn(d1[l1]);
        tmp *= getocn(d2[l2]) - 1;
    }else{
        tmp = getocn(d2[l2]);
        tmp *= getocn(d1[l1]) - 1;
    }
    for(int i = 7 - oc;i >= 7 - oc - len1 - len2;-- i){
        tmp *= i - oc.size();
    }
    return tmp;
}

LL yn(int l1, int l2,set<int> oc){
    oc.insert(d1[l1]);
    return aa(l1 - 1, l2, oc + 1);
}
LL ny(int l1, int l2, set<int> oc){
    oc.insert(d2[l2]);
    return aa(l1, l2 - 1, oc + 1);
}
LL yy(int l1, int l2, set<int> oc){
    oc.insert(d1[l1]);
    oc.insert(d2[l1]);
    return aa(l1 - 1, l2 - 1, oc);

}
int main(){
    RII(n,m);
    getD();
    set<int> oc;
    LL res = 0;
    return aa(len1, len2, oc);
    return 0;
}
