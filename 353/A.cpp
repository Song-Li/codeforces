#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
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
int main(){
    int a,b,c;
    RII(a,b);
    RI(c);
    if(c && (b - a) / c * c == b - a && (b - a) / c >= 0) printf("YES\n");
    else if(!c && a == b) puts("YES");
    else puts("NO");
    return 0;
}
