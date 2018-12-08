#include <bits/stdc++.h>
#define MM 100002
using namespace std;

int parent[MM], dank[MM];

int find(int cur){
  if (cur != parent[cur]) parent[cur] = find(parent[cur]);
  return parent[cur];
}

void merge(int x, int y){
  if (dank[x] > dank[y]) parent[y] = x;
  else{
    parent[x] = y;
    if (dank[x] == dank[y]) dank[y]++;
  }
}

struct quad{
  int a, b, c, d;
};

bool cmp(quad a, quad b){
  if (a.c == b.c) return a.d < b.d;
  return a.c < b.c;
}

vector<quad> edges;
int cnt = 1, me, days = 0;

int main(){
  int n, m, d; scanf("%d%d%d", &n, &m, &d);
  for (int i = 1, a, b, c; i <= m; i++){
    scanf("%d%d%d", &a, &b, &c);
    edges.push_back({a, b, c, i < n ? 0 : 1});
  }
  for (int i = 1; i <= n; i++) parent[i] = i;
  sort(edges.begin(), edges.end(), cmp);
  for (quad cur: edges){
    if (cnt == n) break;
    int first = find(cur.a), second = find(cur.b);
    if (first != second){
      merge(first, second);
      cnt++; me = cur.c;
      if (cur.d == 1) days++;
    }
  }
  for (int i = 1; i <= n; i++) parent[i] = i;
  for (auto cur: edges){
    int first = find(cur.a), second = find(cur.b);
    if (first != second){
      if (cur.c < me || (cur.c == me && cur.d == 0)) merge(first, second);
      else if (cur.d == 0 && cur.c <= d){
        printf("%d\n", days - 1);
        return 0;
      }
    }
  }
  printf("%d\n", days);
  return 0;
}
