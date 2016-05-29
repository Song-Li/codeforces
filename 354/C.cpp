#include <iostream>
#include <string>
using namespace std;
inline int max(int a,int b){ return a > b ? a : b;}
inline int min(int a,int b){ return a < b ? a : b;}
int main(){
    int n,k;
    string a;
    cin >> n >> k;
    cin >> a;
    if(k >= n / 2) {
        cout << n << endl;
        return 0;
    }
    int l = 0,r = 0,ans = 0,cnt = 0;
    for(int i = 0;i < n;++ i){
        if(a[r] != 'a'){
            if(cnt >= k){
                while(a[l] == 'a' && l < n) ++ l;
                ++ l;
            }else
                ++ cnt;
        }
        r ++;
        ans = max(ans, r - l);
    }
    l = 0,r = 0,cnt = 0;
    for(int i = 0;i < n;++ i){
        if(a[r] != 'b'){
            if(cnt >= k){
                while(a[l] == 'b' && l < n) ++ l;
                ++ l;
            }else
                ++ cnt;
        }
        r ++;
        ans = max(ans, r - l);
    }

    cout << ans << endl;
    return 0;
}
