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

string ss;
set<string> suf; 
set<string> ret;

PII dfs(int pos){
    if(pos == len - 1) return MP(-1,-1);
    if(pos == len) return MP(0,0);

    string s2 = ss.substr(pos, 2), s3 = ss.substr(pos, 3);
    int r2, r3;

    if(suf.find(s2) != suf.end()) r2 = 0;
    else {
        suf.insert(s2);
        PII res = dfs(i + 2);
        r2 = res.first + res.second + 1;
    }
    if(suf.find(s3) != suf.end()) r3 = 0;
    else{
        suf.insert(s3);
        PII res = dfs(i + 3);
        r3 = res.first + res.second;
    }
    return MP(r2,r3);
}

int main(){
    cin >> ss;
    dfs(5);
    return 0;
}
