#include <bits/stdc++.h>
#define MM 92
using namespace std;

vector<int> adj[MM];
bool vis[MM]; int dis[MM];

#define l(x, y){      \
  adj[x].push_back(y);\
  adj[y].push_back(x);\
}

int main(){
  char c;
  l(1, 6); l(2, 6); l(3, 6); l(4, 6); l(5, 6);
  l(4, 5); l(3, 4); l(3, 5); l(6, 7); l(3, 15);
  l(15, 13); l(13, 14); l(13, 12); l(12, 11); l(12, 9);
  l(11, 10); l(16, 17); l(16, 18); l(17, 18);
  l(9, 10); l(9, 8); l(8, 7);
  while (true){
    memset(vis, false, MM);
    memset(dis, 0, MM);
    scanf("%c", &c);
    if (c == 'i'){
      int x, y; scanf("%d%d", &x, &y);
      adj[x].push_back(y);
      adj[y].push_back(x);
      continue;
    }if (c == 'd'){
      int x, y; scanf("%d%d", &x, &y);
      int temp = -1;
      for (int i = 0; i < adj[x].size(); i++) if (adj[x][i] == y) temp = i;
      adj[x].erase(adj[x].begin() + temp);
      for (int i = 0; i < adj[y].size(); i++) if (adj[y][i] == x) temp = i;
      adj[y].erase(adj[y].begin() + temp);
      continue;
    }if (c == 'n'){
      int x; scanf("%d", &x);
      printf("%d\n", adj[x].size());
      continue;
    }if (c == 'q') break;
    if (c == 's'){
      int x, y; scanf("%d%d", &x, &y);
      queue<int> q; q.push(x);
      vis[x] = true;
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
      vis[y] ? printf("%d\n", dis[y]) : printf("Not connected\n");
      continue;
    }if (c == 'f'){
      int x; scanf("%d", &x);
      queue<int> q; q.push(x);
      vis[x] = true;
      int cnt = 0;
      while (!q.empty()){
        int cur = q.front(); q.pop();
        if (dis[cur] == 2) cnt++;
        for (int v: adj[cur]){
          if (!vis[v]){
            vis[v] = true;
            q.push(v);
            dis[v] = dis[cur] + 1;
          }
        }
      }
      printf("%d\n", cnt);
      continue;
    }
  }
  return 0;
}
