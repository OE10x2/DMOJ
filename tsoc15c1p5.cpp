#include <bits/stdc++.h>
#define MM 102
using namespace std;

vector<int> adj[MM];
vector<int> ants;
int dis[MM], user[MM]; bool vis[MM], ant[MM];

int main(){
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0, x, y; i < m; i++){
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int w; scanf("%d", &w);
  for (int i = 0, wi; i < w; i++){
    scanf("%d", &wi);
    ants.push_back(wi);
  }
  queue<int> q;
  for (int start: ants){
    memset(vis, false, MM);
    q.push(start);
    vis[start] = true; dis[start] = 0;
    while (!q.empty()){
      int cur = q.front(); q.pop();
      for (int v: adj[cur]){
        if (!vis[v]){
          vis[v] = true;
          q.push(v);
          if (dis[v] != 0) dis[v] = min(dis[v], dis[cur] + 4);
          else dis[v] = dis[cur] + 4;
        }
      }
    }
  }
  memset(vis, false, MM);
  memset(ant, false, MM);
  memset(user, 0, MM);
  q.push(1); vis[1] = true;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    for (int v: adj[cur]){
      if (!vis[v] && !ant[cur]){
        vis[v] = true;
        q.push(v);
        if (user[cur] + 1 < dis[v]) user[v] = user[cur] + 1;
        else ant[v] = true;
      }else if (ant[cur]) ant[v] = true;
    }
  }
  if (user[n] != 0) printf("%d\n", user[n]);
  else printf("sacrifice bobhob314\n");
  return 0;
}
