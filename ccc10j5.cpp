#include <bits/stdc++.h>
#define MM 10
using namespace std;

bool vis[MM][MM]; int dis[MM][MM];

int main(){
  memset(vis, false, sizeof(vis));
  memset(dis, 0, sizeof(dis));
  int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
  queue<pair<int, int>> q; q.push(make_pair(a, b));
  vis[a][b] = true; dis[a][b] = 0;
  while (!q.empty()){
    pair<int, int> cur = q.front(); q.pop();
    if (cur.first >= 3 && cur.second >= 2 && !vis[cur.first-2][cur.second-1]){
      q.push(make_pair(cur.first-2, cur.second-1));
      vis[cur.first-2][cur.second-1] = true;
      dis[cur.first-2][cur.second-1] = dis[cur.first][cur.second] + 1;
    }
    if (cur.first >= 3 && cur.second <= 7 && !vis[cur.first-2][cur.second+1]){
      q.push(make_pair(cur.first-2, cur.second+1));
      vis[cur.first-2][cur.second+1] = true;
      dis[cur.first-2][cur.second+1] = dis[cur.first][cur.second] + 1;
    }
    if (cur.first <= 6 && cur.second >= 2 && !vis[cur.first+2][cur.second-1]){
      q.push(make_pair(cur.first+2, cur.second-1));
      vis[cur.first+2][cur.second-1] = true;
      dis[cur.first+2][cur.second-1] = dis[cur.first][cur.second] + 1;
    }
    if (cur.first <= 6 && cur.second <= 7 && !vis[cur.first+2][cur.second+1]){
      q.push(make_pair(cur.first+2, cur.second+1));
      vis[cur.first+2][cur.second+1] = true;
      dis[cur.first+2][cur.second+1] = dis[cur.first][cur.second] + 1;
    }
    if (cur.first <= 7 && cur.second >= 3 && !vis[cur.first+1][cur.second-2]){
      q.push(make_pair(cur.first+1, cur.second-2));
      vis[cur.first+1][cur.second-2] = true;
      dis[cur.first+1][cur.second-2] = dis[cur.first][cur.second] + 1;
    }
    if (cur.first <= 7 && cur.second <= 6 && !vis[cur.first+1][cur.second+2]){
      q.push(make_pair(cur.first+1, cur.second+2));
      vis[cur.first+1][cur.second+2] = true;
      dis[cur.first+1][cur.second+2] = dis[cur.first][cur.second] + 1;
    }
    if (cur.first >= 2 && cur.second >= 3 && !vis[cur.first-1][cur.second-2]){
      q.push(make_pair(cur.first-1, cur.second-2));
      vis[cur.first-1][cur.second-2] = true;
      dis[cur.first-1][cur.second-2] = dis[cur.first][cur.second] + 1;
    }
    if (cur.first >= 2 && cur.second <= 6 && !vis[cur.first-1][cur.second+2]){
      q.push(make_pair(cur.first-1, cur.second+2));
      vis[cur.first-1][cur.second+2] = true;
      dis[cur.first-1][cur.second+2] = dis[cur.first][cur.second] + 1;
    }
  }
  printf("%d\n", dis[c][d]);
  return 0;
}
