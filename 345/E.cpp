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
int n,m;
int fa[111111];
int fae[111111];
int id[111111];
int ed[111111];
int cnt = 0;
int find(int p){
    while(p != id[p]) {
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}
void Union(int p,int q){
    int pid = find(p);
    int qid = find(q);
    if(pid == qid) return ;
    id[pid] = qid;
}
int main(){
    RII(n,m);
    memset(fa,0,sizeof(fa));
    memset(fae,0,sizeof(fae));
    memset(ed,0,sizeof(ed));
    int f,t;
    int res = 0;
    for(int i = 0;i < n;++ i){
        id[i] = i;
    }
    for(int i = 0;i < m;++ i){
        RII(f,t);
        f --;
        t --;
        Union(f,t);
        ed[f] ++;
        ed[t] ++;
    }
    for(int i = 0;i < n;++ i){
        fae[find(i)] += ed[i];
        fa[find(i)] ++;
    }
    for(int i = 0;i < n;++ i)
        if(fa[i] && fae[i] < 2 * fa[i])
            res ++;

    cout << res << endl;
    return 0;
}
