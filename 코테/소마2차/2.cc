#include <iostream>
#include <algorithm>
#include<cstring>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int N = 300001;
int uf[N];
pi sx[N];
pi sy[N];
int n, m;
int ans = 0;
int find(int x) {
	if (uf[x] < 0)return x;
	return uf[x] = find(uf[x]);
}
void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b)return;
	sx[a] = { min(sx[a].first,sx[b].first),max(sx[a].second,sx[b].second) };
	sy[a] = { min(sy[a].first,sy[b].first),max(sy[a].second,sy[b].second) };
	ans = max(ans, 2 * (sx[a].second - sx[a].first + sy[a].second - sy[a].first));
	uf[b] = a;
}
int main() {
	cin >> n >> m;
	memset(uf, -1, sizeof(uf));
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		sx[i] = { a,a };
		sy[i] = { b,b };
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	cout << ans;
}