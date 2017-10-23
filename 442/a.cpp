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
  string name;
  string friends[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
  cin >> name;
  bool flag = false;
  int count = 0;
  for (string n : friends) {
    size_t nPos = name.find(n, 0); // fist occurrence
    while(nPos != string::npos) {
      count++;
      nPos = name.find(n, nPos+1);
    }
  }
  if (count == 1) {
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }
  return 0;
}
