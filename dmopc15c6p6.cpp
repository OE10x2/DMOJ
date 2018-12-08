#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MM 1502
using namespace std;

vector<short> adj[MM];
short dis[MM]; queue<short> q;
short n, m, k, a, b, i, cnt, cur;

int main(){
  scan(n); scan(m); scan(k);
  while (m--){
    scan(a); scan(b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (i = 1; i <= n; i++){
    memset(dis, 0, sizeof(dis));
    q.push(i); dis[i] = 1;
    cnt = 1;
    while (!q.empty()){
      cur = q.front(); q.pop();
      if (dis[cur] <= k){
        for (int v: adj[cur]){
          if (!dis[v]){
            q.push(v); cnt++;
            dis[v] = dis[cur] + 1;
          }
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
