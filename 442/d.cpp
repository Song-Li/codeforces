#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <set>
#define PII pair<int, int>
#define MP make_pair
#define INF 10000000
using namespace std;
int n, m, k;
int map[1100][1100];
int sx, sy, ex, ey;
bool inarea(int x, int y) {
  return x <= n && x > 0 && y > 0 && y <= m;
} 
void BFS() {
  int dirx[4] = {0, 1, 0, -1};
  int diry[4] = {-1, 0, 1, 0};
  bool flag = false;
  queue<PII> q;
  q.push(MP(sx, sy));
  while(!q.empty()) {
    PII cur = q.front();
    q.pop();
    for (int d = 0;d < 4;++ d) {
      for (int i = 1;i <= k;++ i) {
        int curx = dirx[d] * i + cur.first;
        int cury = diry[d] * i + cur.second;
        if (inarea(curx, cury) && map[curx][cury] == -1) {
          break;
        }
        if (inarea(curx, cury) && map[curx][cury] == INF) {
          map[curx][cury] = map[cur.first][cur.second] + 1;
          if (curx == ex && cury == ey) {
            cout << map[curx][cury] << endl;
            flag = true;
            return ;
          }
          q.push(MP(curx, cury));
        }
      }
    }
  }
  if (!flag) cout << -1 << endl;
}
int main(){
  string ma[1100];
  cin >> n >> m >> k;
  for (int i = 0;i < n;++ i) cin >> ma[i];
  cin >> sx >> sy >> ex >> ey;
  if (sx == ex && sy == ey) {
    cout << 0 << endl;
    return 0;
  }
  memset(map, -1, sizeof(map));
  for (int i = 0;i < n;++ i) {
    for (int j = 0; j < m;++ j) {
      if (ma[i][j] == '.') map[i + 1][j + 1] = INF;
      else if (ma[i][j] == '#') map[i + 1][j + 1] = -1;
    }
  }
  map[sx][sy] = 0;
  BFS();
  return 0;
}
