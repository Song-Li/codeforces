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
  int n,k;
  int flag = false;
  vector<int> nums;
  RII(n,k); 
  int tmp, pre = -1;
  for (int i = 0;i < n;++ i) {
    RI(tmp);
    nums.push_back(tmp);
  }
  int Min = 2147483647;
  for (int i = 0;i < k;++ i) {
    RI(tmp);
    Min = min(tmp, Min);
  }
  int Max = -1;
  if (k > 1) {
    printf("Yes\n");
    return 0;
  }
  else {
    for (int i : nums) {
      if (i == 0) i = Min;
      if (i < Max) {
        printf("Yes\n");
        return 0;
      }
      Max = max(Max, i);
    }
  }
  printf("No\n");
  return 0;
}
