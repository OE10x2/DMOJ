#include <bits/stdc++.h>
#define MM 1502
#define CHECK first >= 1 && first <= n && second >= 1 && second <= n
using namespace std;

int adj[MM][MM];
bool vis[MM][MM];
vector<pair<int, int>> v;

int main(){
  v.emplace_back(1, 0);
  v.emplace_back(0, 1);
  v.emplace_back(-1, 0);
  v.emplace_back(0, -1);
  int n, h; scanf("%d%d", &n, &h);
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &adj[i][j]);
  queue<pair<int, int>> q; q.push({1, 1});
  memset(vis, false, sizeof(vis));
  vis[1][1] = true;
  while (!q.empty()){
    auto cur = q.front(); q.pop();
    if (cur.first == n && cur.second == n){
        printf("yes\n");
        return 0;
    }
    for (auto d: v){
      int first = d.first + cur.first, second = d.second + cur.second;
      if (CHECK && !vis[first][second] && abs(adj[cur.first][cur.second] - adj[first][second]) <= h){
        vis[first][second] = true;
        q.push({first, second});
      }
    }
  }
  printf("no\n");
  return 0;
}
