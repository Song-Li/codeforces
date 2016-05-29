#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#define PII pair<int, int>
#define MP make_pair
#define RI(X) scanf("%d", &(X))
#define RII(X,Y) scanf("%d %d", &(X), &(Y))
using namespace std;
int max(int a,int b){
    return a > b ? a : b;
}
int min(int a,int b){
    return a < b ? a : b;
}
vector<int> dd;
void ins(int n){
    vector<int> tmp;
    while(n / 10){
        tmp.push_back(n % 10);
        n /= 10;
    }
    tmp.push_back(n);
    for(int i = tmp.size() - 1;i >= 0;-- i)
        dd.push_back(tmp[i]);
}
int main(){
    int a;
    RI(a);
    for(int i = 1;i <= 1000;++ i)
        ins(i);
    printf("%d\n",dd[a - 1]);
    return 0;
}
