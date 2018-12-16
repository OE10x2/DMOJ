#include <bits/stdc++.h>
#define MM 252
using namespace std;

int adj[MM][MM], psa[MM][MM];

int main(){
  int w, h, n; scanf("%d%d%d", &w, &h, &n);
  for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) scanf("%d", &adj[j][i]);
  for (int i = 1; i <= w; i++) for (int j = 1; j <= h; j++) psa[i][j] = adj[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
  int ans = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= w; j++){
      for (int k = 1; k <= h; k++){
        if (j + i - 1 <= w && k + n/i - 1 <= h) ans = max(ans, psa[j+i-1][k-1+n/i] - psa[j-1][k-1+n/i] - psa[j+i-1][k-1] + psa[j-1][k-1]);
        else break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
