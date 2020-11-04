#include<bits/stdc++.h>
using namespace std;
bitset<501>dp[1001][501];
int a[1004];
int main(){
    int n;
    cin >> n;
    for(int i = 1 ;i <= 2 * n - 1; i++)cin>>a[i];
    dp[0][0][0]=1;
    for(int i=0; i < 2 * n - 1; i++){
        for(int j =0; j <= n; j++){
            dp[i+1][j] |= dp[i][j];
            dp[i+1][j+1] |= dp[i][j]<<a[i+1]|dp[i][j]>>(n-a[i+1]);
        }
    }
    if(dp[2*n-1][n][0]==0){
        cout << -1;
    }
    else{
        int r=0, x= n ;
        for(int i = 2 * n -1; i; i--){
            if(x&&dp[i-1][x-1][(r-a[i]+n)%n]){
                cout << a[i] <<" ";
                r = (r -a[i]+n)%n;
                x--;
            }
        }
    }
}