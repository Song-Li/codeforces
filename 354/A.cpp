#include <stdio.h>
int max(int a,int b){
    return a > b ? a : b;
}
int min(int a,int b){
    return a < b ? a : b;
}
int main(){
    int n,s,b;
    int array[128];
    scanf("%d",&n);
    for(int i = 0;i < n;++ i)
        scanf("%d",&array[i]);
    for(int i = 0;i < n;++ i){
        if(array[i] == 1) s = i;
        else if(array[i] == n) b = i;
    }
    printf("%d\n", max(n - 1 - min(s,b), max(s,b)));
}
