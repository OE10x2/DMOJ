#include <bits/stdc++.h>
#define MM 52
using namespace std;

int adj[MM][MM], dis[MM][MM];
bool vis[MM][MM];

int main(){
  int t; scanf("%d", &t);
  for (int aa = 0; aa < t; aa++){
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(adj, 0, sizeof(adj));
    int l, w; scanf("%d%d", &l, &w);
    int sx, sy, ex, ey;
    for (int i = 0; i < w; i++){
      char c[MM]; scanf("%s", c);
      for (int j = 0; j < l; j++){
        if (c[j] == 'O') adj[i][j] = 1;
        else if (c[j] == 'X') adj[i][j] = 0;
        else if (c[j] == 'C'){
          sx = i, sy = j;
          adj[i][j] = 1;
        }
        else if (c[j] == 'W'){
          ex = i, ey = j;
          adj[i][j] = 1;
        }
      }
    }
    queue<pair<int, int>> q; q.push(make_pair(sx, sy));
    vis[sx][sy] = true;
    bool check = false;
    while (!q.empty()){
      pair<int, int> cur = q.front(); q.pop();
      if (cur.second < l-1 && adj[cur.first][cur.second+1] == 1 && !vis[cur.first][cur.second+1]){
        vis[cur.first][cur.second+1] = true;
        q.push(make_pair(cur.first, cur.second+1));
        dis[cur.first][cur.second+1] = dis[cur.first][cur.second] + 1;
      }
      if (cur.second > 0 && adj[cur.first][cur.second-1] == 1 && !vis[cur.first][cur.second-1]){
        vis[cur.first][cur.second-1] = true;
        q.push(make_pair(cur.first, cur.second-1));
        dis[cur.first][cur.second-1] = dis[cur.first][cur.second] + 1;
      }
      if (cur.first < w-1 && adj[cur.first+1][cur.second] == 1 && !vis[cur.first+1][cur.second]){
        vis[cur.first+1][cur.second] = true;
        q.push(make_pair(cur.first+1, cur.second));
        dis[cur.first+1][cur.second] = dis[cur.first][cur.second] + 1;
      }
      if (cur.first > 0 && adj[cur.first-1][cur.second] == 1 && !vis[cur.first-1][cur.second]){
        vis[cur.first-1][cur.second] = true;
        q.push(make_pair(cur.first-1, cur.second));
        dis[cur.first-1][cur.second] = dis[cur.first][cur.second] + 1;
      }
    }
    (dis[ex][ey] >= 60 || !vis[ex][ey]) ? printf("#notworth\n") : printf("%d\n", dis[ex][ey]);
  }
  return 0;
}
