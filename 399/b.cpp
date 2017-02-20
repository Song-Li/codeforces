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
//#define RL(X) scanf("%lld", &(X))
//#define RLL(X,Y) scanf("%lld %lld", &(X), &(Y))
#define LL long long 
#define MIN(X,Y) (X)<(Y)?(X):(Y)
#define MAX(X,Y) (X)>(Y)?(X):(Y)
#define INFD 1e32
#define PI 3.14159265358979323
using namespace std;
vector<LL> nums;
vector<LL> pows;
int main(){
  LL n, l, r;
  RLL(n,l);
  RL(r);
  LL cur = 1;
  while(n) {
    nums.push_back(n & 1);
    n >>= 1;
    pows.push_back(cur);
    cur <<= 1;
  }
  reverse(pows.begin(), pows.end());
  LL res = 0;
  LL start;
  LL size = nums.size();
  for (int i = 0;i < size;++ i) {
    start = (l / (pows[i] * 2)) * (pows[i] * 2) + pows[i];
    if (start < l) start += pows[i] * 2;
    if (start > r) continue;
    res += ((r - start) / (pows[i] * 2) + 1) * nums[i];
  }
  cout << res << endl;
  return 0;
}
