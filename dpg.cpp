#include <bits/stdc++.h>
#define MM 100002
using namespace std;

vector<int> adj[MM];
int ind[MM];
queue<pair<int, int>> q;

int main(){
    int N, M; scanf("%d%d", &N, &M);
    for (int i = 1, xi, yi; i <= M; i++){
        scanf("%d%d", &xi, &yi);
        adj[xi].push_back(yi);
        ind[yi]++;
    }
    for (int i = 1; i <= N; i++) if (ind[i] == 0) q.push({i, 0});
    int ans = 0;
    while (!q.empty()){
        auto cur = q.front(); q.pop();
        ans = max(ans, cur.second);
        for (int v: adj[cur.first]) if (--ind[v] == 0) q.push({v, cur.second+1});
    }
    printf("%d\n", ans);
    return 0;
}
