#include <bits/stdc++.h>
#define MM 5282
using namespace std;

int dp[MM];

int main(){
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[0] = 0;
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 1, club; i <= m; i++){
    scanf("%d", &club);
    for (int j = 0; j <= n - club; j++) dp[j+club] = min(dp[j+club], dp[j] + 1);
  }
  dp[n] == 0x3f3f3f3f ? printf("Roberta acknowledges defeat.\n") : printf("Roberta wins in %d strokes.\n", dp[n]);
  return 0;
}
