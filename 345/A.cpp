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
#define RIII(X,Y,Z) scanf("%d %d %d", &(X), &(Y), &(Z))
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
int main(){
    int n;
    long long res = 0;
    int a,b;
    map<int, int> px;
    map<int, int> py;
    map<int, map<int, int> > pos;
    RI(n);
    for(int i = 0;i < n;++ i){
        RII(a,b);
        if(px.find(a) != px.end() || py.find(b) != py.end()){
            res += px[a];
            res += py[b];
            px[a] ++;
            py[b] ++;
            if(pos[a][b]) res -= pos[a][b];
        }else{
            px.insert(MP(a,1));
            py.insert(MP(b,1));
        }
        pos[a][b] ++;
    }
    cout << res << endl;
    return 0;
}
