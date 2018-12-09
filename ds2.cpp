#include <bits/stdc++.h>
using namespace std;

struct triple{
  int a, b, c;
};

int parent[100002], dank[100002];
vector<triple> edges;
vector<int> ans;
int cnt = 1, n, m;

bool cmp(triple a, triple b){
  return a.c < b.c;
}

int find(int x){
  if (parent[x] != x) parent[x] = find(parent[x]);
  return parent[x];
}

void merge(int x, int y){
  if (dank[x] > dank[y]) parent[x] = y;
  else{
    parent[y] = x;
    if (dank[x] == dank[y]) dank[y]++;
    }
}

int main(){
  for (int i = 1; i < 100002; i++) parent[i] = i, dank[i] = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1, a, b; i <= m; i++){
    scanf("%d%d", &a, &b);
    edges.push_back({a, b, i});
  }
  sort(edges.begin(), edges.end(), cmp);
  for (auto cur: edges){
    if (find(cur.a) != find(cur.b)){
      merge(find(cur.a), find(cur.b));
      cnt++;
      ans.push_back(cur.c);
    }
  }
  if (cnt != n) printf("Disconnected Graph\n");
  else for (int i: ans) printf("%d\n", i);
  return 0;
}
