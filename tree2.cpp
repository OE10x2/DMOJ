#include <bits/stdc++.h>
using namespace std;

int sx = 0, sy = 0, smallest = -1;
vector<pair<int, int>> v;
vector<pair<int, int>> drc;
int dis[12][12], steps[12][12], adj[12][12];

int main(){
  drc.emplace_back(0, 1);
  drc.emplace_back(1, 0);
  drc.emplace_back(0, -1);
  drc.emplace_back(-1, 0);
  int r, c; scanf("%d%d", &r, &c);
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      char ch; cin >> ch;
      if (ch == ' ') continue;
      if (ch == '.') adj[i][j] = 0;
      else if (ch == 'X'){
        sx = i, sy = j;
        adj[i][j] = 0;
      }else adj[i][j] = ch - '0';
      smallest = max(smallest, adj[i][j]);
    }
  }
  for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (adj[i][j] == smallest) v.emplace_back(i, j);
  queue<pair<int, int>> q; q.push(make_pair(sx, sy));
  memset(dis, 0x3f, sizeof(dis));
  dis[sx][sy] = 0;
  while (!q.empty()){
    auto cur = q.front(); q.pop();
    for (auto i: drc){
      int f = cur.first + i.first, s = cur.second + i.second;
      if (f >= 0 && f < r && s >= 0 && s < c){
        if (dis[f][s] > dis[cur.first][cur.second] + adj[cur.first][cur.second]){
          dis[f][s] = dis[cur.first][cur.second] + adj[cur.first][cur.second];
          steps[f][s] = steps[cur.first][cur.second] + (adj[cur.first][cur.second] == 0 ? 0 : 1);
          q.push(make_pair(f, s));
        }
      }
    }
  }
  int ans = INT_MAX, distance = INT_MAX;
  for (auto i: v) distance = min(distance, (i.first - sx) * (i.first - sx) + (i.second - sy) * (i.second - sy));
  for (auto i: v) if ((i.first - sx) * (i.first - sx) + (i.second - sy) * (i.second - sy) == distance) ans = min(ans, steps[i.first][i.second]);
  printf("%d\n", ans);
  return 0;
}
