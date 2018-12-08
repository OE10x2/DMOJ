#include <bits/stdc++.h>
#define MM 1002
using namespace std;

vector<int> adj[MM];
int dis[MM][MM];
bool vis[MM];

int main(){
  int n, m, t; scanf("%d%d%d", &n, &m, &t);
  for (int i = 0, a, b; i < m; i++){
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
  }
  for (int i = 1; i <= n; i++){
    memset(vis, false, MM);
    vis[i] = true;
    for (int j = 1; j <= n; j++) dis[i][j] = 0;
    queue<int> q; q.push(i);
    while (!q.empty()){
      int cur = q.front(); q.pop();
      for (int v: adj[cur]){
        if (!vis[v]){
          vis[v] = true;
          q.push(v);
          dis[i][v] = dis[i][cur] + t;
        }
      }
    }
  }
  int q; scanf("%d", &q);
  for (int i = 0, a, b; i < q; i++){
    scanf("%d%d", &a, &b);
    dis[a][b] == 0 ? printf("Not enough hallways!\n") : printf("%d\n", dis[a][b]);
  }
  return 0;
}
