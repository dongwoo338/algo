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
        vector<int>dp(n+1);
        vector<int>a(n+1);
        for(int i = 1; i <=n ; i++)cin >> a[i];
        for(int i= n ; i >= 1; i--){
            dp[i]=a[i];
            int nval = i +a[i];
            if(nval<=n)dp[i]+=dp[nval];
        }
        int ans=0;
        for(int i = 1; i <=n ;i++)ans=max(ans,dp[i]);
        cout << ans << "\n";
    }
}