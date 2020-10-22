#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
ll ans;
vector<int>anv;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>>v(n);
    for(int i =0; i < n ; i++){
        int tm;
        cin >> tm;
        v[i] = {tm,i+1};
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0; i < v.size(); i++){
        anv.push_back(v[i].second);
        ans += i * v[i].first;
    }
    cout <<ans+n << "\n";
    for(int i : anv)cout << i << " ";
}