#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> v(n);
        for(long long &i : v)cin >> i;
        long long maxt = -1e9;
        long long ans=0;
        for(int i = n -1; i >=0; i--){
            if(maxt-v[i]>0)ans += (maxt-v[i]);
            maxt= max(maxt,v[i]);
        }
        cout << ans << "\n";
    }
}