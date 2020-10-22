#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
vector<int> primes;
vector<int> a[1001];
bool check[1001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bitset<1001>v;
    for (int i = 2; i * i <= 1000; i++) {
        if (v[i])continue;
        for (int j = i + i; j <= 1000; j += i) {
            v[j] = 1;
        }
    }
    for (int i = 2; i <= 1000; i++) {
        if (!v[i])primes.push_back(i);
    }
    for (int i = 0; i < primes.size(); i++) {
        for (int j = 0; j < primes.size(); j++) {
            for (int k = 0; k < primes.size(); k++) {
                int sums = primes[i] + primes[j] + primes[k];
                if (sums > 1000)continue;
                if (check[sums])continue;
                vector<int> vu = { primes[i],primes[j],primes[k] };
                sort(vu.begin(), vu.end());
                a[sums] = vu;
                check[sums] = 1;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (check[n]) {
            for (int i : a[n])cout << i << " ";
            cout << "\n";
        }
        else cout << 0 << "\n";
    }
}