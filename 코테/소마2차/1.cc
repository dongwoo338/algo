#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
ll ans = -1e9;
ll ps = 0;
int main(){
	int n;
	cin >> n;
	set<ll>s;
	for (int i = 0; i < n; i++) {
		ll k;
		cin >> k;
		ps += k;
		if (i == 0) ans = max(ans, k);
		else {
			ans = max(ans, ps - *s.begin());
		}
		s.insert(ps);
	}
	cout << ans;
}