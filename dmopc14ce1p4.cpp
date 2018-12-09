#include <bits/stdc++.h>
#define MM 1002
using namespace std;

struct triple{
  int first, second, third;
};

vector<triple> adj[MM];
double dis[MM]; int parent[MM];

bool cmp(triple a, triple b){
  if (a.first == b.first) return double(a.second)/double(a.third)*60 < double(b.second)/double(b.third)*60;
  return a.first < b.first;
}

int main(){
	int v, e; scanf("%d%d", &v, &e);
  for (int i = 0, m, n, d, s; i < e; i++){
    scanf("%d%d%d%d", &m, &n, &d, &s);
    adj[m].push_back({n, d, s});
    adj[n].push_back({m, d, s});
  }
  for (int i = 1; i <= v; i++) sort(adj[i].begin(), adj[i].end(), cmp);
  queue<int> q; q.push(1);
  for (int i = 1; i <= MM; i++) dis[i] = 1e9;
  dis[1] = 0; parent[1] = -1;
  while (!q.empty()){
    int cur = q.front(); q.pop();
    for (auto v: adj[cur]){
      if (dis[cur] + double(v.second)/double(v.third)*60 < dis[v.first]){
        dis[v.first] = dis[cur] + double(v.second)/double(v.third)*60;
        parent[v.first] = cur;
        q.push(v.first);
      }
    }
  }
  int check1 = parent[v], pre = v, cnt = 0; double reduced = 0;
  while (check1 != -1){
    for (auto v: adj[check1]) if (v.first == pre){
      reduced += double(v.second)/double(v.third)*double(80);
      break;
    }
    cnt++;
    pre = check1; check1 = parent[check1];
  }
  printf("%d\n%.0lf\n", cnt, reduced - dis[v]);
  return 0;
}
