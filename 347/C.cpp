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

map<string, string> res;
void generate(){
    string tmp,con = "";
    for(int i = 1989;i < 111111;++ i){
        tmp = to_string(i);
        for(int j = tmp.length() - 1;j >= 0;-- j){
            con = tmp.substr(j);
            if(res.find(con) == res.end()) {
                res[con] = tmp;
                break;
            }
        }
    }
}
int main(){
    int n;
    generate();
    RI(n);
    string in;
    int ret;
    for(int i = 0;i < n;++ i){
        cin >> in;
        in = in.substr(4);
        if(res.find(in) == res.end())
            cout << 1 << in << endl;
        else
            cout << res[in] << endl;
    }
    return 0;
}
