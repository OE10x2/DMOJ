#include <bits/stdc++.h>
#define MM 1002
using namespace std;

int dp[MM];

int main(){
  int c, m; scanf("%d%d", &c, &m);
  for (int i = 0, ni, ki; i < c; i++){
    scanf("%d%d", &ni, &ki);
    for (int j = m; j >= ki; j--) dp[j] = max(dp[j], dp[j-ki] + ni);
  }
  printf("%d\n", dp[m]);
  return 0;
}
