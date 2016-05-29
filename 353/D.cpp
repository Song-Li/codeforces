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
char ss[1024][1024];
int vis[1024][1024][4];
int dir[1024 * 1024 * 4];
int steps[1024 * 1024 * 4];
PII bfs[1024 * 1024 * 4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m; 
int s_x,s_y,e_x,e_y;
int inarea(int x,int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main(){
    RII(n,m);
    for(int i = 0;i < n;++ i) scanf("%s",ss[i]);
    RII(s_x,s_y);
    RII(e_x,e_y);
    s_y --; s_x --; e_x --; e_y --;
    for(int i = 0;i < n;++ i){
        for(int j = 0;j < m;++ j){
            if(ss[i][j] == '+') ss[i][j] = 15;
            else if(ss[i][j] == '-') ss[i][j] = 10;
            else if(ss[i][j] == '|') ss[i][j] = 5;
            else if(ss[i][j] == '^') ss[i][j] = 1;
            else if(ss[i][j] == '>') ss[i][j] = 2;
            else if(ss[i][j] == '<') ss[i][j] = 8;
            else if(ss[i][j] == 'v') ss[i][j] = 4;
            else if(ss[i][j] == 'L') ss[i][j] = 7;
            else if(ss[i][j] == 'R') ss[i][j] = 13;
            else if(ss[i][j] == 'U') ss[i][j] = 14;
            else if(ss[i][j] == 'D') ss[i][j] = 11;
            else if(ss[i][j] == '*') ss[i][j] = 0;

        }
    }
    vis[s_x][s_y][0] = 1;
    bfs[0] = MP(s_x,s_y);
    steps[0] = 0;
    int rr = 1;
    dir[0] = 0;
    if(s_x == e_x && s_y == e_y) return 0 * printf("%d\n",0);
    for(int i = 0;i < rr;++ i){
        int x = bfs[i].first;
        int y = bfs[i].second;
        int dd = dir[i];
        int from = ss[x][y] << dd | ss[x][y] >> (4 - dd);
        for(int j = 0;j < 4;++ j){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(!inarea(nx, ny)) continue;
            if(vis[nx][ny][dd]) continue;
            int to = ss[nx][ny] << dd | ss[nx][ny] >> (4 - dd);
            if(!j){
                if(!(from & 1) || !(to & (1 << 2))) continue;
            }else if(j == 1){
                if(!(from & (1 << 1)) || !(to & (1 << 3))) continue;
            }else if(j == 2){
                if(!(from & (1 << 2)) || !(to & 1)) continue;
            }else if(j == 3){
                if(!(from & (1 << 3)) || !(to & (1 << 1))) continue;
            }
            if(e_x == nx && e_y == ny) return 0 * printf("%d\n", steps[i] + 1);
            vis[nx][ny][dd] = 1;
            bfs[rr] = MP(nx, ny);
            dir[rr] = dd;
            steps[rr ++] = steps[i] + 1;
        }
        if(!vis[x][y][(dd + 1) & 3]) {
            vis[x][y][(dd + 1) & 3] = 1;
            steps[rr] = steps[i] + 1;
            dir[rr] = (dir[i] + 1) & 3;
            bfs[rr ++] = MP(x,y);
        }
    }
    printf("-1\n");
    return 0;
}
