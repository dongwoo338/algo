#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n;
    vector<int>v(n);
    for(int &i:v)cin >> i;
    sort(v.begin(),v.end());
    cin >> m;
    map<int,int>mp;
    for(int i=0; i < m; i++){
        int k;
        cin >> k;
        mp[-k]++;
    }
    if(-mp.begin()->first>v[n-1]){
        cout << -1;
        return 0;
    }
    int ans =0;
    while(!mp.empty()){
        for(int k : v){
            if(mp.lower_bound(-k)!=mp.end()){
                auto it = mp.lower_bound(-k);
                if(!(--it->second))mp.erase(it);
            }
        }
        ans++;
    }
    cout << ans;
}