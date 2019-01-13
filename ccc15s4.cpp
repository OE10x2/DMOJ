#include <bits/stdc++.h>
#define MM 2002
using namespace std;

struct triple{
    int a, b, c;
};

vector<triple> adj[MM];
int dis[MM][MM];
bool inq[MM];

int main(){
    int k, n, m; scanf("%d%d%d", &k, &n, &m);
    for (int i = 0, ai, bi, ti, hi; i < m; i++){
        scanf("%d%d%d%d", &ai, &bi, &ti, &hi);
        adj[ai].push_back({bi, ti, hi});
        adj[bi].push_back({ai, ti, hi});
    }
    int a, b; scanf("%d%d", &a, &b);
    queue<int> q; q.push(a);
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(inq, false, sizeof(inq));
    dis[a][0] = 0; inq[a] = true;
    while (!q.empty()){
        int cur = q.front();
        inq[cur] = false; q.pop();
        for (auto v: adj[cur]){
            for (int i = 0; i < k - v.c; i++){
                int temp = dis[cur][i] + v.b;
                if (temp < dis[v.a][v.c + i]){
                    dis[v.a][v.c + i] = temp;
                    if (!inq[v.a]){
                        inq[v.a] = true;
                        q.push(v.a);
                    }
                }
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < k; i++) ans = min(ans, dis[b][i]);
    printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
    return 0;
}
