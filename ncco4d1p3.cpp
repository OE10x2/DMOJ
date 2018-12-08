#include <bits/stdc++.h>
#define MM 100002
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[MM];
vector<pii> dis;

int main(){
  for (int i = 0; i < MM; i++) dis.emplace_back(0x3f3f3f3f, 0x3f3f3f3f);
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0, a, b, w; i < m; i++){
    scanf("%d%d%d", &a, &b, &w);
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }
  priority_queue<pii, vector<pii>, greater<pii>> q;
  dis[1] = {0, 0x3f3f3f3f}; q.push({0, 1});
  while (!q.empty()){
    pii cur = q.top(); q.pop();
    for (auto v: adj[cur.second]){
      if (cur.first + v.second < dis[v.first].first){
        dis[v.first].second = dis[v.first].first;
        dis[v.first].first = cur.first + v.second;
        q.push({dis[v.first].first, v.first});
      }else if (dis[v.first].first < cur.first + v.second && cur.first + v.second < dis[v.first].second){
        dis[v.first].second = cur.first + v.second;
        q.push({dis[v.first].second, v.first});
      }
    }
  }
  printf("%d\n", dis[n].second);
  return 0;
}
