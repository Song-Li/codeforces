#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <math.h>
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
double getDis(PDD from, double tox, double toy){
    return sqrt((from.first - tox) * (from.first - tox) + (from.second - toy) * (from.second - toy));
}
int main(){
    double ax,ay,bx,by,tx,ty;
    int n;
    PDD pos[111111];
    PDD a,b,t;
    double dis[111111];
    RDD(ax,ay);
    RDD(bx,by);
    RDD(tx,ty);
    RI(n);
    double ta,tb; 
    for(int i = 0;i < n;++ i){
        RDD(ta, tb);
        if(ta == tx && tb == ty){
            i --;
            n --;
            continue;
        }
        pos[i] = MP(ta,tb); 
    }
    double ma = INFD, mb = INFD, msa = INFD, msb = INFD;
    int ida = -1, idb = -1;
    for(int i = 0;i < n;++ i)
        dis[i] = getDis(pos[i], tx,ty);
    for(int i = 0;i < n;++ i){
        ta = getDis(pos[i], ax, ay);
        if(ta - dis[i] < ma){
            msa = ma;
            ma = ta - dis[i];
            ida = i;
        }else if(ta - dis[i] < msa) msa = ta - dis[i];
        ta = getDis(pos[i], bx, by);
        if(ta - dis[i] < mb){
            msb = mb;
            mb = ta - dis[i];
            idb = i;
        }else if(ta - dis[i] < msb) msb = ta - dis[i];
    }
    double res = 0;
    if(!n) return 0 * printf("0\n");
    if(ma > 0 || mb > 0) res = MIN(ma,mb);
    else if(ida == idb){
        if(msa > 0) msa = 0;
        if(msb > 0) msb = 0;
        res = MIN(msa + mb, msb + ma);
    }else{
        res = ma + mb;
    }
    for(int i = 0;i < n;++ i)
        res += dis[i] * 2;
    printf("%.12lf\n",res);
    return 0;
}
