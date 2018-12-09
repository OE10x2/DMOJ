#include <bits/stdc++.h>
using namespace std;

struct triple{
  int a, b, c;
};

vector<triple> edges;
int parent[100002], dank[100002];
int n, k, cnt = 0, ans = 0, i, w;

bool cmp(triple a, triple b){
  return a.c < b.c;
}

int find(int cur){
  if (parent[cur] != cur) parent[cur] = find(parent[cur]);
  return parent[cur];
}

void merge(int x, int y){
  if (dank[x] > dank[y]) parent[x] = y;
  else{
    parent[y] = x;
    dank[y] += dank[x] == dank[y];
  }
}

int main(){
  scanf("%d%d", &n, &k);
  for (i = 1; i < n; i++){
    scanf("%d", &w);
    edges.push_back({i, i+1, w});
    parent[i] = i;
  }
  for (i = 1; i < n-k+1; i++) edges.push_back({i, i+k, 0});
  sort(edges.begin(), edges.end(), cmp);
  for (auto cur: edges){
    if (cnt == n-1) break;
    if (find(cur.a) != find(cur.b)){
      merge(find(cur.a), find(cur.b));
      cnt++;
      ans += cur.c;
    }
  }
  printf("%d\n", ans);
  return 0;
}
