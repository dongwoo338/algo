#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ans=0;
        map<int,int>mp;
        while(n--){
            int k;
            cin >> k;
            mp[k]++;
        }
        while(m--){
            int k;
            cin >> k;
            mp[k]++;
        }
        for(auto &[f,s]:mp){
            if(s==2)ans++;
        }
        cout << ans << "\n";
    }
}