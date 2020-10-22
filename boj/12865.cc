#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n , k;
int dp[100001];
int ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i =0; i <n; i++){
        int w, c;
        cin >> w >> c;
        for(int j = k; j-w>=0; j--){
            dp[j] = max(dp[j], dp[j - w] + c);
        }
    }
    for(int i =0; i <=k; i++)ans=max(ans,dp[i]);
    cout << ans;
}