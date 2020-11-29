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
        int n;
        cin >> n;
        vector<int>v(n);
        map<int,int>mp;
        for(int &i: v){
            cin >> i;
            mp[i]++;
        }
        int ansv = (int)1e9;
        int ans = -1;
        for(int i =0; i < n; i++){
            int val = v[i];
            if(mp[val]==1&&val<ansv){
                ansv=val;
                ans = i+1;
            }
        }
        cout << ans << "\n";
    }
}