#include <bits/stdc++.h>
#define MM 100002
using namespace std;

vector<int> check;
vector<int> adj[MM];
bool vis[MM]; int dis1[MM], dis2[MM];

int main(){
  int n, m, k, a, b; scanf("%d%d%d%d%d", &n, &m, &k, &a, &b);
  for (int i = 0, si; i < k; i++) scanf("%d", &si), check.push_back(si);
  for (int i = 0, ai, bi; i < m; i++){
    scanf("%d%d", &ai, &bi);
    adj[ai].push_back(bi);
    adj[bi].push_back(ai);
  }
  queue<int> q; q.push(a);
  memset(vis, false, MM);
  dis1[a] = 0; vis[a] = true;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    for (int v: adj[cur]){
      if (!vis[v]){
        vis[v] = true;
        q.push(v);
        dis1[v] = dis1[cur] + 1;
      }
    }
  }
  q.push(b);
  memset(vis, false, MM);
  dis2[b] = 0; vis[b] = true;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    for (int v: adj[cur]){
      if (!vis[v]){
        vis[v] = true;
        q.push(v);
        dis2[v] = dis2[cur] + 1;
      }
    }
  }
  int ans = INT_MAX;
  for (int i: check) ans = min(ans, dis1[i] + dis2[i]);
  printf("%d\n", ans);
  return 0;
}
