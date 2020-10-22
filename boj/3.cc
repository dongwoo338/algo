#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
const ll MOD =998244353;
ll dp[200001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    dp[1] = 10;
    for(int i = 2; i <= n; i++){
       dp[i] = dp[i-1]*i%MOD;
    }
    for(int i = n; i >= 1; i--)cout << dp[i] << " ";
}