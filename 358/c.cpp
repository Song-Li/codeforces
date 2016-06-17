#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <math.h>
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
#define RL(X) scanf("%lld", &(X))
#define RLL(X,Y) scanf("%lld %lld", &(X), &(Y))
#define LL long long 
#define MIN(X,Y) (X)<(Y)?(X):(Y)
#define MAX(X,Y) (X)>(Y)?(X):(Y)
#define INFD 1e32
#define PI 3.14159265358979323
using namespace std;
int ret = 0;
LL dd[111111];
int del[111111];
int vis[111111];
vector<pair<LL,LL> > ed[111111];
void solve(pair<LL,LL> node, LL sum, int flag){
    if(del[node.first]) return ;
    vis[node.first] = 1;
    if(node.first == 3) cout << sum << ' ' << node.second << endl;
    if(flag == -1 || sum + node.second > dd[node.first]){
        del[node.first] = 1;
        cout << node.first << ' ' << dd[node.first] << endl;
        ret ++;
        for(int i = 0;i < ed[node.first].size();++ i){
            if(node.first == 2) cout << "hehe" << ed[node.first][i].first << endl;
            if(vis[ed[node.first][i].first]) {
                ed[node.first].erase(ed[node.first].begin() + i);
                -- i;
            }
            else solve(ed[node.first][i], sum, -1);
        }
    }
    else{
        for(int i = 0;i < ed[node.first].size();++ i){
            if(node.first == 2) cout << "hehe" << ed[node.first][i].first << endl;
            if(vis[ed[node.first][i].first]) {
                ed[node.first].erase(ed[node.first].begin() + i);
            }
            else solve(ed[node.first][i], sum + node.second, 1);
        }
    }
}
int main(){
    memset(vis, 0, sizeof(vis));
    memset(del, 0, sizeof(del));
    int n;
    LL ta, tb;
    RI(n);
    for(int i = 0;i < n;++ i)
        RL(dd[i]);
    for(int i = 0;i < n - 1;++ i){
        RLL(ta,tb);
        ed[i + 1].push_back(MP(ta - 1,tb));
        ed[ta - 1].push_back(MP(i + 1, tb));
    }
    solve(MP(0,0), 0, 1);
    memset(vis, 0, sizeof(vis));
    for(int i = 1;i < 1;++ i){
        solve(MP(i,0), 0, 1);
    }
    cout << ret << endl;
    return 0;
}
