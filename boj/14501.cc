#include<bits/stdc++.h>
using namespace std;
int n;
int d[501];
int c[501];
int ans;
int dp[501];
int main(){
    int n;
    for(int i=0; i < n ;i++){
        cin >> d[i] >> c[i];
    }
    for(int i =0; i< n; i++){
        int next=i+d[i];
        if(next<n)dp[next]=max(dp[next],dp[i]+c[i]);
    }
    for(int i =0; i < n; i++)ans =max(ans,dp[i]);
    cout<<ans;
}
