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
#include <unordered_map>
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
map<int, int> pri;
const int mod_num = 1000000007;
void getPri(int n) {
  bool flag[1000000];
  memset(flag, true, sizeof(flag));
  int con = 0;
  for (int i = 2;i <= n;++ i) {
    if (flag[i]) pri[i] = 0;
    for (auto j : pri) {
      if (i * j.first > n) break;
      flag[i * j.first] = false;
      if (!(i % j.first)) break;
    }
  }
}
int main(){
  int n, res = 0;
  int a[200000];
  int cur_max = -1;
  RI(n);
  for (int i = 0;i < n;++ i) {
    RI(a[i]);
    cur_max = MAX(cur_max, a[i]);
  }
  getPri(cur_max);
  for (int i = 0;i < n;++ i) {
    res += a[i];
    res %= mod_num;
    for (auto p : pri) {
      if (p.first > a[i]) break;
      if (a[i] % p.first == 0) {
        pri[p.first] ++;
      }
    }
  } 
  for (auto p : pri) {
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}
