#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <map>
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
#define eps 1e-7
using namespace std;
double getDis(double* p1, double* p2) {
  double res = 0;
  for (int i = 0;i < 5;++ i) {
    res += (p2[i] - p1[i]) * (p2[i] - p1[i]);
  }
  return res;
}
int main(){
  int n;
  double p[1010][5];
  RI(n);
  for (int i = 0;i < n;++ i) {
    for (int j = 0;j < 5;++ j) {
      cin >> p[i][j];
    }
  }

  double cur_min = INFD;
  double cur_dis;
  int mp1, mp2, m21, m22;
  for (int i = 0;i < n;++ i) {
    for (int j = i + 1;j < n;++ j) {
      cur_dis = getDis(p[i], p[j]);
      if (cur_min >= cur_dis) {
        cur_min = cur_dis;
        mp1 = i;
        mp2 = j;
      }
    }
  }

  double md[5];
  for (int i = 0;i < 5;++ i) {
    md[i] = (p[mp1][i] + p[mp2][i]) / 2;
  }

  int res[1010];
  int cnt = 0;
  for (int i = 0;i < n;++ i) {
    if (i == mp1 || i == mp2)  {
      int good = true;
      for(int j = 0;j < n;++ j) {
        if (j == i) continue;
        for (int k = j + 1;k < n;++ k) {
          int tmp_res = 0;
          for (int z = 0;z < 5;++ z) {
            tmp_res += (p[j][z] - p[i][z]) * (p[k][z] - p[i][z]);
          }
          if(tmp_res > 0) {
            good = false;
            break;
          }
        }
        if (!good) break;
      }
      if (good) res[cnt ++] = i + 1;
    }

    else if ((getDis(p[i] , md) - cur_min / 2) < eps) res[cnt ++] = i + 1;
  }

  printf("%d\n", cnt);
  for (int i = 0;i < cnt;++ i) {
    printf("%d\n", res[i]);
  }
  return 0;
}
