#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int a[201];
int dp[202][404];//~까지봣을때 현재값이 i일때
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i =0; i <n; i++)cin >> a[i];
        sort(a,a+n);
        int ans=(int)1e9;
        fill(&dp[0][0],&dp[201][403],(int)MAX);
        for(int i = 1; i <= 400; i++)dp[0][i]=abs(i-a[0]);
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= 400; j++){
                for(int k = 1; k< j; k++){
                    if(dp[i-1][k]==MAX)continue;
                    dp[i][j] =min(dp[i][j],dp[i-1][k]+abs(j-a[i]));
                }
            }
        }
        for(int i =0; i<= 400; i++)ans=min(ans,dp[n-1][i]);
        cout << ans <<"\n";
    }
}