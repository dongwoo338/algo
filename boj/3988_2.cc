#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x;
    cin >> n>>x;
    vector<int>a(n);
    for(int &i :a)cin >> i;
    sort(a.begin(),a.end());
    int cs = n-1-x;
    vector<int>v;//diff
    for(int i = 1; i < n; i++)v.push_back(a[i]-a[i-1]);
    deque<pi> dq;
    int ps= 0 , ans = (int)1e9;
    for(int i =0; i < n -1; i++){
        if(i >= cs)ps -= v[i-cs];
        ps += v[i];
        while(dq.size()&&(i-dq.front().second)>=i)dq.pop_front();
        while(dq.size()&&(dq.back().first>v[i]))dq.pop_back();
        dq.push_back({v[i],i});
        if(i>=cs-1) ans=min(ans,ps+dq.front().first);
    }
    cout << ans;
}