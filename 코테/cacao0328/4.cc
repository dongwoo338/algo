#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
/*vector<long long> solution(long long k, vector<long long> room_number) {
    set<ll> s;
    for(ll i : room_number){
        
    }
    vector<long long> answer;
    return answer;
}*/
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k;
    cin >> k;
    vector<ll>rn;
    for(int i =0; i< k ; i++){
        ll e;
        cin >> e;
        rn.push_back(e);
    }
    map<ll,ll>mp;
    for(int i =0; i < k; i++){
        ll aus;
        mp[rn[i]]++;
        auto it =prev(mp.lower_bound(rn[i]));
        cout << it->first;
    }
    //solution(k, rn);
}