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

void dfs(int pos){
    int len = ss.length();
    if(pos == len){
        for(auto i : suf)
            ret.insert(i);
        return ;
    }
    if(pos > len) return ;

    string s2 = ss.substr(pos, 2), s3 = ss.substr(pos, 3);
    int r2, r3;

    if(s2.length() != 2 || suf.find(s2) != suf.end()) r2 = 0;
    else {
        suf.insert(s2);
        dfs(pos + 2);
        suf.erase(s2);
    }
    if(s3.length() != 3 || suf.find(s3) != suf.end()) r3 = 0;
    else{
        suf.insert(s3);
        dfs(pos + 3);
        suf.erase(s3);
    }
}

int main(){
    cin >> ss;
    int len = ss.length();
    for(int i = 0;i < len - 1;++ i)
        dfs(5 + i);
    cout << ret.size() << endl;
    for(auto i : ret)
        cout << i << endl;
    return 0;
}
