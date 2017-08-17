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
double res = 0;

void dfs(vector<int> *r, bool * vis, int dep, int cur, double posi) {
  vis[cur] = true;
  bool stop = true;
  vector<int> pendding;
  for (auto i : r[cur]) {
    if (!vis[i]) {
      pendding.push_back(i);
    }
  }

  if (!pendding.size()) {
    res += posi * (double)dep;
  }
  posi *= 1.0 / (double)pendding.size();

  for (auto i : pendding) {
      dfs(r, vis, dep + 1, i, posi);
  }
  vis[cur] = false;
}

int main(){
  int n, s, e;
  RI(n);
  vector<int> r[100005];
  bool vis[100005];
  memset(vis, 0, sizeof(vis));
  for (int i = 1;i < n;++ i) {
    RII(s,e);
    r[s].push_back(e);
    r[e].push_back(s);
  }
  dfs(r, vis, 0, 1, 1);
  printf("%lf\n", res);
  return 0;
}
