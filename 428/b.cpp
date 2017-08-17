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
  int n,k, tmp;
  int num_4, num_2, num_1;
  priority_queue<int> que;
  RII(n,k);
  for (int i = 0;i < k;++ i) {
    RI(tmp);
    que.push(tmp);
  }
  num_4 = n;
  num_2 = n * 2;
  num_1 = 0;

  while(!que.empty()) {
    tmp = que.top();
    que.pop();
    if (num_4 > 0) {
      num_4 --;
      if (tmp == 2) num_1 ++;
      else if (tmp == 1) num_2 ++;
      tmp -= 4; 
    } else if (num_2 > 0) {
      num_2 --;
      tmp -= 2;
    } else if (num_1 > 0) {
      num_1 --;
      tmp -= 1;
    } else {
      printf("NO\n");
      return 0;
    }
    if (tmp > 0) que.push(tmp);
  }
  printf("YES\n");
  return 0;
}
