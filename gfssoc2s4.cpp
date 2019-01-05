#include <bits/stdc++.h>
#define MM 500002
using namespace std;

vector<pair<int, int>> adj1[MM];
vector<pair<int, int>> adj2[MM];
int dis1[MM], dis2[MM];
queue<int> q;

int main(){
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0, a, b, k; i < m; i++){
    scanf("%d%d%d", &a, &b, &k);
    adj1[a].emplace_back(b, k);
    adj2[b].emplace_back(a, k);
  }
  memset(dis1, 0x3f3f3f3f, MM);
  q.push(1); dis1[1] = 0;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    for (auto v: adj1[cur]){
      if (dis1[v.first] > dis1[cur] + v.second){
        dis1[v.first] = dis1[cur] + v.second;
        q.push(v.first);
      }
    }
  }
  memset(dis2, 0x3f3f3f3f, MM);
  q.push(n); dis2[n] = 0;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    for (auto v: adj2[cur]){
      if (dis2[v.first] > dis2[cur] + v.second){
        dis2[v.first] = dis2[cur] + v.second;
        q.push(v.first);
      }
    }
  }
  int ans = dis1[n];
  int d; scanf("%d", &d);
  for (int i = 0, a, b, g; i < d; i++){
    scanf("%d%d%d", &a, &b, &g);
    ans = min(ans, dis1[a] + dis2[b] + g);
  }
  printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
  return 0;
}
