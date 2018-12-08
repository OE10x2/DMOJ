#include <bits/stdc++.h>
#define MM 1002
using namespace std;

bool vis[MM][MM];

struct triple{
  int first, second; string t;
  triple(int a, int b, string s){
    first = a, second = b, t = s;
  }
};

int main(){
  int va, vb, m; scanf("%d%d%d", &va, &vb, &m);
  queue<triple> q; q.push(triple(0, 0, ""));
  bool check = false;
  while (!q.empty()){
    triple cur = q.front(); q.pop();
    if (cur.first == m || cur.second == m){
      cout << cur.t;
      check = true;
      break;
    }
    if (vis[cur.first][cur.second]) continue;
    vis[cur.first][cur.second] = true;
    q.push(triple(va, cur.second, cur.t + "fill A\n"));
    q.push(triple(cur.first, vb, cur.t + "fill B\n"));
    q.push(triple(0, cur.second, cur.t + "chug A\n"));
    q.push(triple(cur.first, 0, cur.t + "chug B\n"));
    if (cur.first + cur.second - vb >= 0) q.push(triple(cur.first + cur.second - vb, vb, cur.t + "pour A B\n"));
    else q.push(triple(0, cur.first + cur.second, cur.t + "pour A B\n"));
    if (cur.first + cur.second - va >= 0) q.push(triple(va, cur.first + cur.second - va, cur.t + "pour B A\n"));
    else q.push(triple(cur.first + cur.second, 0, cur.t + "pour B A\n"));
  }
  if (!check) printf("Not possible\n");
  return 0;
}
