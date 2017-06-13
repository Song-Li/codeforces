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
int main(){
  int n;
  bool visited[1001];
  memset(visited, 0, sizeof(visited));
  RI(n);
  int a[1001], b[1001], res[1001];
  int nums[4], cnt = 0;
  for (int i = 0;i < n;++ i) RI(a[i]);
  for (int i = 0;i < n;++ i) RI(b[i]);
  for (int i = 0;i < n;++ i) {
    if (a[i] == b[i]) visited[a[i]] = 1;
    res[i] = a[i];
  }
  for (int i = 1;i <= n;++ i) {
    if (!visited[i]) nums[cnt ++] = i;
  }
  for (int i = 0;i < n;++ i) {
    if (a[i] != b[i]) res[i] = nums[-- cnt];
  }
  int diff = 0;
  for (int i = 0;i < n;++ i) {
    if (a[i] != res[i]) diff ++;
    if (b[i] != res[i]) diff ++;
  }
  if (diff != 2) {
    cnt = 0;
    for (int i = 0;i < n;++ i) {
      if (a[i] != b[i]) res[i] = nums[cnt ++];
    }
  }
  for (int i = 0;i < n;++ i) printf("%d ", res[i]);
  printf("\n");
  return 0;
}
