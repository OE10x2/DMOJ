#include <bits/stdc++.h>
#define MM 500002
using namespace std;

vector<int> adj[MM];
bool vis[MM]; int dis[MM], dis1[MM], dis2[MM];

int main(){
  memset(dis, 0, MM);
  memset(dis1, 0, MM);
  memset(dis2, 0, MM);
  memset(vis, false, MM);
  int n; scanf("%d", &n);
  for (int i = 1, a, b; i < n; i++){
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q; q.push(1);
  vis[1] = true;
  int max_dis = 0, node;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    if (dis[cur] > max_dis){
      max_dis = dis[cur];
      node = cur;
    }
    for (int v: adj[cur]){
      if (!vis[v]){
        vis[v] = true; q.push(v);
        dis[v] = dis[cur] + 1;
      }
    }
  }
  memset(vis, false, MM); 
  q.push(node); vis[node] = true;
  max_dis = 0; int node2;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    if (dis1[cur] > max_dis){
      max_dis = dis1[cur];
      node2 = cur;
    }
    for (int v: adj[cur]){
      if (!vis[v]){
        vis[v] = true; q.push(v);
        dis1[v] = dis1[cur] + 1;
      }
    }
  }
  memset(vis, false, MM); 
  q.push(node2); vis[node2] = true;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    for (int v: adj[cur]){
      if (!vis[v]){
        vis[v] = true; q.push(v);
        dis2[v] = dis2[cur] + 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%d\n", max(dis1[i], dis2[i]) + 1);
  return 0;
}
