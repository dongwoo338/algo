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
        vector<int>dp(5);
        int n;
        cin >> n;
        dp[2]=1;
        for(int i=0; i < n; i++){
            int k;
            cin >> k;
            vector<int>ne;
            for(int j =0; j <= 4; j++){
                if(dp[j]){
                    int nval = j+k;
                    if(nval<=4)ne.push_back(nval);
                    nval = j-k;
                    if(nval>=0)ne.push_back(nval);
                }
            }
            for(int &i : dp)i=0;
            for(int &i : ne)dp[i]=1;
        }
        if(dp[2])cout<<"YES\n";
        else cout<<"NO\n";
    }
}