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
#define RL(X) scanf("%lld", &(X))
#define RLL(X,Y) scanf("%lld %lld", &(X), &(Y))
#define LL long long 
#define MIN(X,Y) (X)<(Y)?(X):(Y)
#define MAX(X,Y) (X)>(Y)?(X):(Y)
#define INFD 1e32
#define PI 3.14159265358979323
using namespace std;
LL getDis(LL x1,LL y1, LL x2, LL y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main(){
  LL a1, a2, b1, b2, c1, c2;
  RLL(a1, a2);
  RLL(b1, b2);
  RLL(c1, c2);
  if ((b1 - a1 == c1 - b1) && (b2 - a2 == c2 - b2)) {
    printf("No\n");
  }
  else if (getDis(a1, a2, b1, b2) == getDis(b1, b2, c1, c2)) {
    printf("Yes\n");
  }else {
    printf("No\n");
  }
  return 0;
}
