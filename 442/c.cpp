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
  cin >> n;
  if (n == 2) {
    cout << 3 << endl << 2 << ' ' << 1 << ' ' << 2 << endl; 
    return 0;
  }
  if (n == 3) {
    cout << 4 << endl << 2 << ' ' << 1 << ' ' << 3 << ' ' << 2 << endl; 
    return 0;
  }
  if (n == 4) {
    cout << 6 << endl << 2 << ' ' << 1 << ' ' << 3 << ' ' << 4 << ' ' << 3 << ' ' << 2 << endl; 
    return 0;
  }
  cout << n + n - 3 << endl;
  cout << 2 << ' ' << 1 << ' ' << n - 1 << ' ' << n << ' ';
  for (int i = 3;i < n;++ i) cout << i << ' ';
  for (int i = n - 3;i > 1;-- i) cout << i << ' ';
  cout << endl;
  return 0;
}
