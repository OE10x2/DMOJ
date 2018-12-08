#include <bits/stdc++.h>
#define MM 200002
typedef long long ll;
using namespace std;

vector<pair<ll, ll>> adj[MM];
ll dis[MM], dis1[MM], dis2[MM]; bool vis[MM];

int main(){
  memset(vis, false, MM); memset(dis, 0, MM);
  ll n, t; scanf("%lld%lld", &n, &t);
  ll add = 0;
  for (ll i = 1, a, b, c; i < n; i++){
    scanf("%lld%lld%lld", &a, &b, &c);
    adj[a].emplace_back(b, c);
    adj[b].emplace_back(a, c);
    add += c;
  }
  queue<ll> q; q.push(1); vis[1] = true;
  ll longest = -1, node1, node2;
  while (!q.empty()){
    ll cur = q.front(); q.pop();
    if (dis[cur] > longest){
      longest = dis[cur];
      node1 = cur;
    }
    for (auto v: adj[cur]){
      if (!vis[v.first]){
        vis[v.first] = true;
        q.push(v.first);
        dis[v.first] = dis[cur] + v.second;
      }
    }
  }
  memset(vis, 0, MM); memset(dis1, 0, MM);
  longest = 0; q.push(node1); vis[node1] = true;
  while (!q.empty()){
    ll cur = q.front(); q.pop();
    if (dis1[cur] > longest){
      longest = dis1[cur];
      node2 = cur;
    }
    for (auto v: adj[cur]){
      if (!vis[v.first]){
        vis[v.first] = true;
        q.push(v.first);
        dis1[v.first] = dis1[cur] + v.second;
      }
    }
  }
  memset(vis, 0, MM); memset(dis2, 0, MM);
  q.push(node2); vis[node2] = true;
  while (!q.empty()){
    ll cur = q.front(); q.pop();
    for (auto v: adj[cur]){
      if (!vis[v.first]){
        vis[v.first] = true;
        q.push(v.first);
        dis2[v.first] = dis2[cur] + v.second;
      }
    }
  }
  for (ll i = 1; i <= n; i++) if (adj[i].size() == t) printf("%lld %lld\n", i, 2*add - max(dis1[i], dis2[i]));
  return 0;
}
