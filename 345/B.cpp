#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <set>
#include <map>
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
int n,m;
struct data{
    int sc,r;
    string name;
};

multimap<int, string> r[11111];

int main(){
    RII(n,m);
    string ts;
    int ti,tc;
    for(int i = 0;i < n;++ i){
        cin >> ts >> ti >> tc;
        r[ti].insert(MP(tc,ts));
    }
    for(int i = 1;i <= m;++ i){
        if(r[i].size()){
            auto it = r[i].end();
            -- it;
            -- it;
            if(r[i].size() > 2 && it->first == (-- it)->first)
                cout << '?' << endl;
            else{
                string n1;
                if(r[i].size() > 2) n1 = (++ it)->second;
                else n1 = it->second;
                string n2 = (++ it)->second;
                cout << n1 << ' ' << n2 << endl;
            }
        }
    }

    return 0;

}
