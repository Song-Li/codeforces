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
int main(){
    int n,a;
    int dd[128];
    int res = 0;
    RII(n,a);
    for(int i = 0;i < n;++ i){
        RI(dd[i]);
    }
    a --;
    int vis[128];
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < n;++ i){
        int op = a + a - i;
        if(vis[i]) continue;
        if(op < 0) res += dd[i];
        else if(i == a) res += dd[i];
        else if(op >= n) res += dd[i];
        else if(dd[i] && dd[op]) res += 2;
        if(op < n) vis[op] = 1;
        vis[i] = 1;
    }
    cout << res << endl;
    return 0;

}
