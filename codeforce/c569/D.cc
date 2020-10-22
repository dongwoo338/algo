#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> v;
int main() {
	cin >> n >> m;
	cout << __builtin_ctz(n);
	for (int i = 1; i < (1 << n); i++) {
		if (__builtin_popcount(i) == m) {
			v.push_back({ 32 - __builtin_clz(i),i });
		}
	}
	sort(v.begin(), v.end());
	for (auto k : v) {
		for (int j = 0; j < n; j++) {
			if (k.second & (1 << j))cout << j + 1 << " ";
		}
		cout << "\n";
	}
}
