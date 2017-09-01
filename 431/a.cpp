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
using namespace std;
bool check(int * cur, int num, int size) {
  if (size <= 0 && (num & 1)) return true;
  if (!(cur[0] & 1)) return false;
  for (int i = 0;i < size;i += 2) {
    if (cur[i] & 1) {
      if (check(cur + i + 1,  num + 1, size - i - 1)) return true;
    }
  }
  return false;
}

int main(){
  int n;
  int cur[105];
  RI(n);
  for (int i = 0;i < n;++ i) {
    RI(cur[i]);
  }
  if (check(cur, 0, n)) printf("Yes\n");
  else printf("No\n");

  return 0;
}
