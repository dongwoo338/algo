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
        map<int,int>mp;// elem prev loc
        map<int,int>mp2;// cnt
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i =0; i < n; i++){
            int k;
            cin >> k;
            v[i]=k;
            if(!mp.count(k)){
                mp[k]=i;
                mp2[k]=2;
            }
            else{
                if(i - mp[k] !=1)mp2[k]++;
                mp[k]=i;
            }
        }
        mp2[v[0]]--;
        mp2[v[n-1]]--;
        int ans =(int)1e9;
        for(auto k : mp2)ans=min(ans,k.second);
        if(ans==n)cout<<0<<"\n";
        else cout << ans<<"\n";
    }
}