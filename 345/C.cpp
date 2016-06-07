#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <set>
#include <unordered_set>
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

int main(){
    int n,m,ti;
    vector<int>res;
    int l;
    RII(n,m);
    l = m;
    unordered_set<int> o;
    for(int i = 0;i < n;++ i){
        cin >> ti;
        o.insert(ti); 
    }
    for(int i = 1;i <= m;++ i){
        if(o.find(i) == o.end()){
            if(l >= i) {
                l -= i;
                res.push_back(i);
            }
            else break;
        }
    }
    cout << res.size() << endl;
    for(int i = 0;i < res.size();++ i)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}
