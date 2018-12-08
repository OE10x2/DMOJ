#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MM 2500002
using namespace std;

vector<pair<int, int>> adj[MM];
vector<pair<int, int>> pencil;
int dis[MM];

int main(){
  memset(dis, 0x3f3f, MM);
  int n, t; scan(n); scan(t);
  for (int i = 0, x, y, c; i < t; i++){
    scan(x); scan(y); scan(c);
    adj[x].emplace_back(y, c);
    adj[y].emplace_back(x, c);
  }
  int k; scan(k);
  for (int i = 0, z, pz; i < k; i++){
    scan(z); scan(pz);
    pencil.emplace_back(z, pz);
  }
  int dest; scan(dest);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  dis[dest] = 0; q.push({0, dest});
  while (!q.empty()){
    pair<int, int> cur = q.top(); q.pop();
    if (dis[cur.second] < cur.first) continue;
    for (auto v: adj[cur.second]){
        if (dis[cur.second] + v.second < dis[v.first]){
            dis[v.first] = dis[cur.second] + v.second;
            q.push({dis[v.first], v.first});
        }
    }
  }
  int ans = 0x3f3f3f;
  for (auto v: pencil) ans = min(ans, dis[v.first] + v.second);
  printf("%d\n", ans);
  return 0;
}
