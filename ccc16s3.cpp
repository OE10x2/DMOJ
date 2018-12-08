#include <bits/stdc++.h>
#define MM 100002
using namespace std;

vector<int> adj[MM], adj2[MM];
bool pho[MM]; int dis[MM];

int diameter, cnt = 0, start;

void prun(int cur, int pre){
  if (dis[cur] > diameter && pho[cur]) diameter = dis[cur], start = cur;
  for (int v: adj[cur]){
    if (v != pre){
      dis[v] = dis[cur] + 1;
      prun(v, cur);
      if (pho[v] || !adj2[v].empty()){
        adj2[cur].push_back(v);
        adj2[v].push_back(cur);
        cnt++;
      }
    }
  }
}

void dfs(int cur, int pre){
  if (dis[cur] > diameter) diameter = dis[cur], start = cur;
  for (int v: adj2[cur]){
    if (v != pre){
      dis[v] = dis[cur] + 1;
      dfs(v, cur);
    }
  }
}

int main(){
  memset(pho, false, MM);
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0, v; i < m; i++){
    scanf("%d", &v);
    pho[v] = true;
    start = v;
  }
  for (int i = 1, a, b; i < n; i++){
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  prun(start, -1);
  dis[start] = 0;
  diameter = 0;
  dfs(start, -1);
  printf("%d\n", 2 * cnt - diameter);
  return 0;
}
