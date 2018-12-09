#include <bits/stdc++.h>
#define MM 2000002
#define MN 1000002
using namespace std;

vector<int> adj[MM];
double chances[MN];

int main(){
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0, ai, aj; i < m; i++){
    scanf("%d%d", &ai, &aj);
    adj[ai].push_back(aj);
  }
  chances[1] = 1;
  for (int i = 1; i <= n; i++){
      for (int v: adj[i]) chances[v] += chances[i] / double(adj[i].size());
      if (adj[i].size() == 0) printf("%.9lf\n", chances[i]);
  }
  return 0;
}
