#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n , k;
vector<int> v;
int ans = 1e9;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    v.resize(n);
    for(int &i : v)cin >> i;
    sort(v.begin(),v.end());
    int vl = n-k-1;
    deque<pi> dq;//diff
    for(int i =0; i < n; i++){
        while(!dq.empty() && dq.front().second < i-vl) dq.pop_front();
        if(i>1){
           while(!dq.empty() && dq.back().first > v[i]-v[i-1])dq.pop_back();
           dq.push_back({v[i]-v[i-1],i-1});
        }
        if(i>=vl)ans=min(ans,v[i]-v[i-vl]+dq.front().first);
    }
    cout << ans;
}