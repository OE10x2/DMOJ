#include <bits/stdc++.h>
#define MM 1002
typedef long long ll;
using namespace std;

ll adj[MM][MM], dis[MM][MM];
bool vis[MM][MM];
vector<pair<ll, ll>> v;

int main(){
  ll r, c; scanf("%lld%lld", &r, &c);
  ll sx, sy, ex, ey; scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
  for (ll i = 0; i < r; i++){
    char ca[MM]; scanf("%s", ca);
    for (ll j = 0; j < c; j++) adj[i][j] = (ca[j] == 'O' ? 1 : 0);
  }
  ll t; scanf("%lld", &t);
  for (ll i = 0, a, b; i < t; i++){
    scanf("%lld%lld", &a, &b);
    v.emplace_back(a, b);
  }
  queue<pair<ll, ll>> q; q.push(make_pair(sx, sy));
  vis[sx][sy] = true;
  ll minus = 1e9;
  while (!q.empty()){
    pair<ll, ll> cur = q.front(); q.pop();
    if (binary_search(v.begin(), v.end(), cur)) minus = min(minus, dis[cur.first][cur.second]);
    if (cur.first > 0 && !vis[cur.first-1][cur.second] && adj[cur.first-1][cur.second] == 1){
      vis[cur.first-1][cur.second] = true;
      q.push(make_pair(cur.first-1, cur.second));
      dis[cur.first-1][cur.second] = dis[cur.first][cur.second] + 1;
    }
    if (cur.second > 0 && !vis[cur.first][cur.second-1] && adj[cur.first][cur.second-1] == 1){
      vis[cur.first][cur.second-1] = true;
      q.push(make_pair(cur.first, cur.second-1));
      dis[cur.first][cur.second-1] = dis[cur.first][cur.second] + 1;
    }
    if (cur.first < r-1 && !vis[cur.first+1][cur.second] && adj[cur.first+1][cur.second] == 1){
      vis[cur.first+1][cur.second] = true;
      q.push(make_pair(cur.first+1, cur.second));
      dis[cur.first+1][cur.second] = dis[cur.first][cur.second] + 1;
    }
    if (cur.second < c-1 && !vis[cur.first][cur.second+1] && adj[cur.first][cur.second+1] == 1){
      vis[cur.first][cur.second+1] = true;
      q.push(make_pair(cur.first, cur.second+1));
      dis[cur.first][cur.second+1] = dis[cur.first][cur.second] + 1;
    }
  }
  if (minus > dis[ex][ey]) printf("0\n");
  else printf("%lld\n", dis[ex][ey] - minus);
  return 0;
}
