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
int looped(vector<int>& a, vector<int>& b) {
  if (a.size() != b.size()) return 0;
  for (int i = 0;i < a.size();++ i) {
    if (a[i] != b[i]) return 0;
  }
  return 1;
}
int main(){
  int n, k, x;
  RII(n,k);
  RI(x);
  vector<int> v;
  int tmp;
  for (int i = 0;i < n;++ i) {
    RI(tmp);
    v.push_back(tmp);
  }
  vector<int> rmin, rmax;
  vector<int> init;
  while(1) {
    sort(v.begin(), v.end());
    if (looped(init, v))
      break;
    if (init.size() == 0) {
      init = v;
    }
    rmin.push_back(v[0]);
    rmax.push_back(v[v.size() - 1]);
    for (int i = 0;i < n;i += 2) {
      v[i] ^= x;
    }
  }
  cout << rmax[k % rmax.size()] << ' ' << rmin[k % rmin.size()] << endl;
  return 0;
}
