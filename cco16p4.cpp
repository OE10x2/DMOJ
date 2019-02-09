#include <bits/stdc++.h>
#define MM 12
using namespace std;

unordered_map<string, int> check;
set<string> pos;
bool flip[MM][MM];
char line[MM];

int main(){
  int N, G; scanf("%d%d", &N, &G);
  for (int i = 0; i < G; i++){
    memset(flip, 0, sizeof(flip));
    for (int j = 1; j <= N; j++){
      scanf("%s", line);
      for (int k = 1; k <= N; k++) flip[j][k] = line[k-1] == 'R';
    }
    for (int j = 1; j < N; j++){
      for (int k = 1; k < N; k++){
        if (flip[j][k] == 0){
          flip[j][k] = !flip[j][k];
          flip[j][k+1] = !flip[j][k+1];
          flip[j+1][k] = !flip[j+1][k];
          flip[j+1][k+1] = !flip[j+1][k+1];
        }
      }
    }
    string temp;
    for (int j = 1; j <= N; j++) temp += flip[N][j] == 1 ? 'R' : 'W';
    for (int j = N-1; j >= 1; j--) temp += flip[j][N] == 1 ? 'R' : 'W';
    check[temp]++;
    pos.insert(temp);
  }
  int ans = 0;
  for (string i: pos) ans += check[i] * (check[i]-1) / 2;
  printf("%d\n", ans);
  return 0;
}
