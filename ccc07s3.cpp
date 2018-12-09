#include <bits/stdc++.h>
#define MM 100002
using namespace std;

int dis[MM]; bool vis[MM];
vector<int> adj[MM];

int BFS(int start, int end){
  memset(vis, false, MM); memset(dis, 0, MM);
  queue<int> q; q.push(start); vis[start] = true; dis[start] = 0;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    for (int v: adj[cur]){
      if (!vis[v]){
        vis[v] = true;
        q.push(v);
        dis[v] = dis[cur] + 1;
      }
    }
  }
  return dis[end] - 1;
}

int main(){
  int n; scanf("%d", &n);
  for (int i = 0, a, b; i < n; i++){
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
  }
  int m1 = -1, n1 = -1;
  do{
    scanf("%d%d", &m1, &n1);
    if (m1 == 0 && n1 == 0) break;
    int ans = BFS(m1, n1);
    if (ans == -1) printf("No\n");
    else printf("Yes %d\n", ans);
  }while (m1 != 0 && n1 != 0);
  return 0;
}
