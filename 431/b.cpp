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
#define START 1000000002
using namespace std;
int main(){
  int n;
  int num[1005];
  RI(n);

  double slop = START;
  bool finished = true;
  for (int i = 0;i < n;++ i) {
    RI(num[i]);
    if (i >= 2 && (num[i] - num[i - 1] != num[i - 1] - num[i - 2])) finished = false;
  }
  if (finished) {
    printf("No\n");
    return 0;
  }
  
  for (int i = 1;i < n;++ i) {
    finished = true;
    slop = START;
    for (int j = 1;j < n;++ j) {
      if (i == j) continue;
      double cur = (double)(num[j] - num[0]) / (double)(j);
      double cur2 = (double)(num[j] - num[i]) / (double)(j - i);
      if (slop == START) {
        slop = cur;
        continue;
      }
      if (cur != slop && cur2 != slop) {
        finished = false;
        break;
      }
    }
    if (finished) {
      printf("Yes\n");
      return 0;
    }

    finished = true;
    slop = START;
    for (int j = 1;j < n;++ j) {
      if (i == j) continue;
      double cur = (double)(num[j] - num[0]) / (double)(j);
      double cur2 = (double)(num[j] - num[i]) / (double)(j - i);
      if (slop == START) {
        slop = cur2;
        continue;
      }
      if (cur != slop && cur2 != slop) {
        finished = false;
        break;
      }
    }

    if (finished) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
