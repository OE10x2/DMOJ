#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int dp[1002][10002];

int main(){
    int N, C; scanf("%d%d", &N, &C);
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++){
        dp[i][0] = 1;
        for (int j = 1; j <= C; j++){
            if (j >= i) dp[i][j] = (dp[i-1][j] - dp[i-1][j-i] + MOD) % MOD;
            else dp[i][j] = dp[i-1][j];
            dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    printf("%d\n", dp[N][C]);
    return 0;
}
