#include <bits/stdc++.h>
#define MM 100002
using namespace std;

vector<pair<int, int>> adj[MM];
int dis1[MM], dis2[MM];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main(){
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0, a, b, t; i < m; i++){
    scanf("%d%d%d", &a, &b, &t);
    adj[a].emplace_back(b, t);
    adj[b].emplace_back(a, t);
  }
  memset(dis1, 0x3f, sizeof(dis1));
  memset(dis2, 0x3f, sizeof(dis2));
  q.push({0, 0}); dis1[0] = 0;
  while (!q.empty()){
    int cur = q.top().second; q.pop();
    for (auto v: adj[cur]){
      if (dis1[cur] + v.second < dis1[v.first]){
        dis1[v.first] = dis1[cur] + v.second;
        q.push({dis1[v.first], v.first});
      }
    }
  }
  q.push({0, n-1}); dis2[n-1] = 0;
  while (!q.empty()){
    int cur = q.top().second; q.pop();
    for (auto v: adj[cur]){
      if (dis2[cur] + v.second < dis2[v.first]){
        dis2[v.first] = dis2[cur] + v.second;
        q.push({dis2[v.first], v.first});
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < n-1; i++) ans = max(ans, dis1[i] + dis2[i]);
  printf("%d\n", ans);
  return 0;
}
