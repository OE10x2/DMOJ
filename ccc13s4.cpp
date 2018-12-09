#include <bits/stdc++.h>
#define MM 1000002
using namespace std;

vector<int> adj[MM];

bool BFS(int s, int t){
  queue<int> q; q.push(s);
  bool vis[MM]; memset(vis, false, MM);
  vis[s] = true;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    for (int v: adj[cur]){
      if (!vis[v]){
        vis[v] = true;
        q.push(v);
      }
    }
  }
  return vis[t];
}

int main(){
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < m; i++){
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
  }
  int p, q; scanf("%d%d", &p, &q);
  if (BFS(p, q)) printf("yes\n");
  else if (BFS(q, p)) printf("no\n");
  else printf("unknown\n");
  return 0;
}
