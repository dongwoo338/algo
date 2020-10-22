#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
map<int,int>mp;
int ans,c;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m,k;
    cin >> n >> m>>k;
    vector<pi>a[2001];
    for(int i=0; i < k; i++){
        int s,e,c;
        cin >> s >> e >> c;
        a[s].push_back({e,c});
    }
    for(int i=0; i <= n; i++){
        if(mp.count(i)){
            ans += mp[i];
            c -= mp[i];
            mp.erase(mp.begin());
        }
        for(auto k : a[i]){
            mp[k.first]+=k.second;
        }
        while(c>m){
            auto lm = prev(mp.end());
            if(c-lm->second>=m){
                c-=lm->second;
                mp.erase(lm);
            }
            else{
                c=m;
                mp[lm->first]-=(c-m);
            }
        }
    }
    cout << ans;
}