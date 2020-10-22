#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n;
vector<pi>v;
int ans = 1e9;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i =0; i < n; i++){
        int k;
        cin >> k;
        v.push_back({k,i});
    }
    sort(v.begin(),v.end());
    for(auto i : v){
        int maxt = max(i.second,n-1-i.second);
        ans = min(ans, i.first/maxt);
    }
    cout << ans;
}