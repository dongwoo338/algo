#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int T, n, k;
int ans;

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