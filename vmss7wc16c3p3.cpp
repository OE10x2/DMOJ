#include <bits/stdc++.h>
#define MM 5002
using namespace std;

vector<pair<int, int>> adj[MM];
int dis[MM]; bool vis[MM];
int n, m, b, q;

void bfs(int start){
  queue<int> que;
  que.push(start);
  memset(vis, false, MM);
  vis[start] = true; dis[start] = 0;
  while (!que.empty()){
    int cur = que.front(); que.pop();
    for (auto v: adj[cur]){
      if (!vis[v.first]){
        vis[v.first] = true;
        dis[v.first] = dis[cur] + v.second;
        que.push(v.first);
      }else if (dis[cur] + v.second < dis[v.first]){
        dis[v.first] = dis[cur] + v.second;
        que.push(v.first);
      }
    }
  }
}

int main(){
  scanf("%d%d%d%d", &n, &m, &b, &q);
  for (int i = 0, x, y, z; i < m; i++){
    scanf("%d%d%d", &x, &y, &z);
    adj[x].emplace_back(y, z);
    adj[y].emplace_back(x, z);
  }
  bfs(b);
  for (int i = 0, a; i < q; i++){
    scanf("%d", &a);
    printf("%d\n", vis[a] ? dis[a] : -1);
  }
  return 0;
}
