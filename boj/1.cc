#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int t,n,k;
int dp[10000002];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 1; i <= 10000001; i++){
        if(dp[i-1] > 1e7)dp[i] = 1e7+1;
        else dp[i] =dp[i - 1] + (i-1);
    }
    while(t--){
        cin >> n >> k;
        bool isok=1;
        n -=k;
        if(n < 0 || n%2==1)isok=0;
        else{
            n/=2;
            if(dp[k] > n)isok=0;
        }
        if(isok)cout <<"YES"<<"\n";
        else cout << "NO"<<"\n";
    }
}