#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>seg;
void build(int ind, int s, int e, vector<int>& v) {
	if (s == e) {
		seg[ind] = { v[s] };
		return;
	}
	int mid = (s + e) >> 1;
	build(ind << 1, s, mid, v);
	build(ind << 1 | 1, mid + 1, e, v);
	auto& L = seg[ind << 1];
	auto& R = seg[ind << 1 | 1];
	merge(L.begin(), L.end(), R.begin(), R.end(), back_inserter(seg[ind]));
}
int query(int ind, int s, int e, int l, int r, int x) {//x보다 큰 원소의 개수 return
	if (l >= s && r <= e) {
		return seg[ind].end() - upper_bound(seg[ind].begin(), seg[ind].end(), x);
	}
	if (r < s || l > e)return 0;
	int mid = (l + r) >> 1;
	return query(ind << 1, s, e, l, mid, x) + query(ind << 1 | 1, s, e, mid + 1, r, x);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int>v(n);
	seg.resize(4 * n);
	for (int& i : v)cin >> i;
	build(1, 0, n - 1, v);
	int m;
	cin >> m;
	int p = 0;
	for (int i = 0; i < m; i++) {
		int s, e, x;
		cin >> s >> e >> x;
		s ^= p; e ^= p; x ^= p;
		s--; e--;
		p = query(1, s, e, 0, n - 1, x);
		cout << p << "\n";
	}
}