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
  string str;
  cin >> str;
  int na[5100], nb[5100];
  memset(na, 0, sizeof(na));
  memset(nb, 0, sizeof(nb));

  int len = str.length();

  for (int i = 1;i < len + 1;++ i) {
    na[i] = na[i - 1] + (str[i - 1] == 'a');
    nb[i] = nb[i - 1] + (str[i - 1] == 'b');
  }

  int Max = -1;
  for (int i = 0;i <= len;++ i) {
    for (int j = i;j <= len;++ j) {
      Max = MAX(Max, na[i] + nb[j] - nb[i] + na[len] - na[j]);
    }
  }
  cout << Max << endl;

  return 0;
}
