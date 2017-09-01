#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 15000000
bool res[MAX];
int pri[1000000];
bool flag[MAX];
int count = 0;

void getpr(int n){
	int i,j;
	memset(flag,true,sizeof(flag));
	for(i = 2;i <= n;++ i){
		if(flag[i]) pri[count ++] = i;
		for(j = 0;j < count && i * pri[j] <= n;++ j){
			flag[i * pri[j]] = false;
			if(!(i % pri[j])) break;
		}
	}
}

void getPri(int n) {
  memset(res, true, sizeof(res));
  for (int i = 2;i < n; ++ i) {
    if (!res[i]) continue;
    else pri[count ++] = i;
    for (int j = i;j * i < n;++ j) {
      res[i * j] = false;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  getPri(n);
  printf("%d\n", count);
  return 0;
}
