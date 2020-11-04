#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<pi>v;// num, cnt
    map<int, int>mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        mp[k]++;
    }
    for (auto k : mp)v.push_back({ k.first,k.second });
    for (int i = 0; i < v.size() - 1; i++) {
        vector<int>tmp;// 연속된 원소의 index를 담는 벡터
        int pos = i;
        while (pos < v.size() - 1 && v[pos + 1].first - v[pos].first == 1) {
            tmp.push_back(pos);
            pos++;
            if (tmp.size() == 3)break;
        }
        if (tmp.empty())continue;
        if (tmp.size() == 1) {// 연속 원소가 2개
            swap(v[i], v[i + 1]);
        }
        else if (tmp.size() <= 3) {// 연속 원소가 3,4개
            swap(v[i + 1], v[i + 2]);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].second; j++) {
            cout << v[i].first << " ";
        }
    }
}