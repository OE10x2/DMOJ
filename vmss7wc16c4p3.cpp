#include <bits/stdc++.h>
#define MM 1002
using namespace std;

int dp[MM][MM];

int main(){
    int D, I, R; scanf("%d%d%d", &D, &I, &R);
    string A, B; cin >> A >> B;
    for (int i = 0; i <= B.length(); i++) dp[0][i] = I * i;
    for (int i = 0; i <= A.length(); i++) dp[i][0] = D * i;
    for (int i = 1; i <= A.length(); i++){
        for (int j = 1; j <= B.length(); j++){
            if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(min(dp[i-1][j] + D, dp[i][j-1] + I), dp[i-1][j-1] + R);
        }
    }
    printf("%d\n", dp[A.length()][B.length()]);
    return 0;
}
