#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int T, n, k, m;
int ans;
int mod;
string s;
int mstoi(string s) {
	int ret = 0;
	for (char c : s) {
		ret %= mod;
		ret *= 10;
		ret += (c - '0');
	}
	return ret;
}
void sol() {
	vector<int>v;
	int now = mstoi(s.substr(0, k));
	v.push_back(now);
	for (int i = k; i < n; i++) {
		now %= mod;
		now *= 10;
		now += (s[i] - '0');
		v.push_back(now);
	}
	sort(v.begin(), v.end());
	deque<int> dq;
	for (int i : v) {
		dq.push_back(i);
		while (i - dq.front() > m)dq.pop_front();
		ans = max(ans, (int)dq.size());
	}
}
void solv() {
	cin >> n >> k >> m;
	cin >> s;
	ans = 0;
	mod = (int)pow(10, k-1);
	sol();
	for (int i = 0; i < n; i++) {
		char o = s[i];
		s[i] = '1';
		sol();
		s[i] = o;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{

		solv();
		cout << "Case #" << test_case + 1 << endl;
		cout << ans << endl;
	}
}