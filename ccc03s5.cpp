#include <bits/stdc++.h>
#define MM 10002
using namespace std;

int parent[MM], dank[MM], dis[MM], weight[MM];

struct triple{
	int a, b, c;
};

vector<triple> edges;

bool cmp(triple x, triple y){
	return x.c > y.c;
}

int find(int i){
	if (parent[i] != i) parent[i] = find(parent[i]);
	return parent[i];
}

void merge(int x, int y, int c){
	if (dank[x] > dank[y]){
		parent[y] = x;
		dis[x] += dis[y];
		weight[x] = min(c, min(weight[x], weight[y]));
	}
	else{
		parent[x] = y;
		dis[y] += dis[x];
		weight[y] = min(c, min(weight[x], weight[y]));
		if (dank[x] == dank[y])	dank[y]++;
	}
}

int main(){
	dis[1] = 1;
  int c, r, d; scanf("%d%d%d", &c, &r, &d);
	fill(weight, weight + c + 1, INT_MAX);
	for (int i = 0, a, b, c; i < r; i++){
    scanf("%d%d%d", &a, &b, &c);
		edges.push_back({a, b, c});
	}
	for (int i = 1; i <= c; i++) parent[i] = i;
	for (int i = 0, des; i < d; i++){
		scanf("%d", &des);
		dis[des] = 1;
	}
	sort(edges.begin(), edges.end(), cmp);
	for (auto i: edges){
		int a = find(i.a), b = find(i.b);
		if (a != b){
			merge(a, b, i.c);
			if (dis[a] == d + 1 || dis[b] == d + 1){
				printf("%d\n", weight[find(1)]);
				break;
			}
		}
	}
  return 0;
}
