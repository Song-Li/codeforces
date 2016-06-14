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
#define RIII(X,Y,Z) scanf("%d %d %d", &(X), &(Y),&(Z))
#define RD(X) scanf("%lf", &(X))
#define RDD(X,Y) scanf("%lf %lf", &(X), &(Y))
#define RF(X) scanf("%f", &(X))
#define RFF(X,Y) scanf("%f %f", &(X), &(Y))
#define RL(X) scanf("%I64d", &(X))
#define RLL(X,Y) scanf("%I64d %I64d", &(X), &(Y))
#define LL __int64
#define MIN(X,Y) (X)<(Y)?(X):(Y)
#define INFD 1e32
using namespace std;
int main(){
    multiset<int> q;
    vector<int> ops;
    vector<int> nums;
    int n,num;
    int total = 0;
    string op;
    RI(n);
    for(int i = 0;i < n;++ i){
        cin >> op;
        if(op == "insert"){
            cin >> num;
            ops.push_back(0);
            nums.push_back(num);
            q.insert(num);
        }else if(op == "removeMin"){
            if(q.empty()){
                ops.push_back(0);
                nums.push_back(0);
            }
            ops.push_back(1);
            nums.push_back(1);
            if(!q.empty())
                q.erase(q.begin());
        }else{
            cin >> num;
            if(q.empty() || (!q.empty() && *(q.begin()) != num)){
                auto low = q.lower_bound(num);
                int dis = distance(q.begin(), low);
                q.erase(q.begin(), low);
                total += dis - 1;
                ops.push_back(1);
                nums.push_back(dis);
                if(q.empty() || (!q.empty() && *(q.begin()) != num)){
                    ops.push_back(0);
                    nums.push_back(num);
                    q.insert(num);
                }
            }
            ops.push_back(2);
            nums.push_back(num);
        }
    }
    cout << ops.size() + total << endl;
    for(int i = 0;i < ops.size();++ i){
        if(ops[i] == 1){
            for(int j = 0;j < nums[i];++ j){
                cout << "removeMin" << endl;
            }
        }else if(ops[i] == 0){
            cout << "insert " << nums[i] << endl;
        } else{
            cout << "getMin "  << nums[i] << endl;
        }
    }
    return 0;
}
