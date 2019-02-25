#include <bits/stdc++.h>
using namespace std;

struct triple{
  int a, b, c;
};

int main(){
  for (int aa = 0; aa < 5; aa++){
    int N; scanf("%d", &N);
    int ans = 0;
    vector<triple> store;
    for (int i = 0, A, B, C, D, E, F, G, H, I, U, V; i < N; i++){
      scanf("%d%d%d%d%d%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F, &G, &H, &I, &U, &V);
      store.push_back({A*U*U+B*U+C, D*U*U+E*U+F, G*U*U+H*U+I});
      store.push_back({A*V*V+B*V+C, D*V*V+E*V+F, G*V*V+H*V+I});
    }
    for (auto i: store) for (auto j: store) ans = max(ans, abs(i.a - j.a) + abs(i.b - j.b) + abs(i.c - j.c));
    printf("%d\n", ans);
  }
  return 0;
}
