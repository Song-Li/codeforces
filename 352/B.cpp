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
int main(){
    int n;
    RI(n);
    string dd;
    cin >> dd;
    int cnt = 0;
    int vis[26];
    memset(vis, 0, sizeof(vis));
    if(n > 26) return 0*printf("-1\n");
    for(int i = 0;i < n;++ i){
        if(vis[dd[i] - 'a']) cnt ++;
        else vis[dd[i] - 'a'] = 1;
    }
    printf("%d\n",cnt);
    return 0;
}
