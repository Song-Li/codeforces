#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1e5
const float eps = 1e-10;
float a[12][12];
float out[12][12];
void addOne(int n){
    out[0][0] = 2;
    for(int i = 1;i <= n;++ i){
        for(int j = 1;j <= n;++ j){
            a[i][j] += out[i - 1][j - 1] / 2 + out[i - 1][j] / 2;
            if(a[i][j] > 1){
                out[i][j] = a[i][j] - 1;
                a[i][j] = 1;
            }
        }
    }
}
void solve(int n, int t){
    for(int i = 0;i < t;++ i){
        addOne(n);
    }
    return ;
}
int main(){
    int n,t;
    int count = 0;  
    scanf("%d %d",&n,&t);
    memset(out,0,sizeof(float) * 12 * 12);
    memset(a,0,sizeof(float) * 12 * 12);
    solve(n,t);
    for(int i = 1;i <= 10;++ i)
        for(int j = 1;j <= 10;++ j)
            if(fabs(a[i][j] - 1.0) < eps){
                count ++;
            }
    printf("%d\n",count);
    return 0;
    
}
