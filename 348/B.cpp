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
int n;
int inarea(int pos){
    return pos >= 0 && pos < n;
}
int main(){
    int dis[111111];
    int vis[111111];
    memset(vis, 0, sizeof(vis));
    string dir;
    int pos = 0;
    RI(n);
    cin >> dir;
    for(int i = 0;i < n;++ i)
        RI(dis[i]);
    while(1){
        if (!inarea(pos)) return 0 * printf("FINITE\n");
        if (vis[pos]) return 0 * printf("INFINITE\n");
        vis[pos] = 1;
        if (dir[pos] == '>') pos += dis[pos];
        else pos -= dis[pos];
    }
    return 0;

}
