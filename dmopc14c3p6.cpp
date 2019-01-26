#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
using namespace std;

int dp[10002];

int main(){
    int n, t; scanf("%d%d", &n, &t);
    for (int i = 0, p1, v1, p2, v2, p3, v3; i < n; i++){
        scanf("%d%d%d%d%d%d", &p1, &v1, &p2, &v2, &p3, &v3);
        for (int j = t; j >= p1; j--){
            dp[j] = max(dp[j], dp[j - p1] + v1);
            if (j >= p2) dp[j] = max(dp[j], dp[j - p2] + v2);
            if (j >= p3) dp[j] = max(dp[j], dp[j - p3] + v3);
        }
    }
    printf("%d\n", dp[t]);
    return 0;
}
