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
int n,m,p;
int inarea(int x,int y){
    return x >= 0 && x < m && y >= 0 && y < n;
}
int main(){
    int dis[31000], qx[31000], qy[31000], val[31000], vis[310][310];
    int mat[310][310];
    RII(n,m);
    RI(p);
    for(int i = 0;i < n;++ i){
        for(int j = 0;j < m;++ j){
            RI(mat[i][j]);
        }
    }
    int h = 0,t = 1;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    memset(vis,0,sizeof(vis));
    int x,y,nx,ny,res;
    qx[0] = 0;
    qy[0] = 0;
    vis[0][0] = 1;
    dis[0] = 0;
    while(h != t){
        x = qx[h];
        y = qy[h];
        for(int i = 0;i < 4;++ i){
            nx = dx[i] + qx[h];
            ny = dy[i] + qy[h];
            if(inarea(nx,ny) && !vis[nx][ny]){
                if(mat[nx][ny] == val[h]){
                    if(val[h] == p) return 0 * printf("%d\n",dis[h] + 1);
                    val[t] = val[h] + 1;
                    memset(vis, 0, sizeof(vis));
                }else
                    val[t] = val[h];
                qx[t] = nx;
                qy[t] = ny;
                dis[t ++] = dis[h] + 1;
                vis[nx][ny] = 1;
            }
        }
    }

    printf("%I64d\n",res);
    return 0;
}
