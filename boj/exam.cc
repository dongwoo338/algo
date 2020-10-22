#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
typedef pair<int,int> pi;
pair<int, int> p = { 0,0 };
vector<pi>anv;
int main() {
    cin >> n >> m;
    while (1) {
        auto tp = p;
        while (tp.first>=0&&tp.second<=m-1) {
            anv.push_back({tp.first,tp.second});
            tp.first--; tp.second++;
        }
        if (p.first == n - 1 && p.second == m - 1)break;
        if (p.first != n - 1)p.first++;
        else p.second++;
    }
    sort(anv.begin(),anv.end());
    for(auto i : anv)cout << i.first+1<< " "<<i.second+1 << "\n";
}