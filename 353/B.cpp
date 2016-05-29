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
int n;
int cv(int i){
    return i > 0 && i <= n;
}
int main(){
    int a,b,c,d;
    RII(n,a);
    RII(b,c);
    RI(d);
    long long int cnt = 0;
    int bc = b - c, ab = a - b, ad = a - d;
    for(int i = 1;i <= n;++ i){
        int j = i + bc;
        int m = i + ad;
        int n = j + ad;
        if(cv(j) && cv(m) && cv(n)) cnt ++;
    }
    cout << cnt * (long long int)n << endl;
    return 0;
}
