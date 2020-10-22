#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
map<int, vector<pair<int, int>>>mp;
const int N = 100001;
int ans[N];
int n;
vector<int> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		mp[s].push_back({ e,i });
	}
	for (auto i : mp) {
		for (auto j : i.second) {
			ans[j.second] = v.end() - upper_bound(v.begin(), v.end(), i.first);
		}
		for (auto j : i.second) {
			v.push_back(j.first);
		}
		sort(v.begin(), v.end());
	}
	for (int i = 0; i < n; i++)cout << ans[i] << "\n";
}