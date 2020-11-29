#include<bits/stdc++.h>
using namespace std;
const int N = 301;
int a[301][21];
int dp[301][21];
int btr[N][21];
int ans[21];
int n,m;
int main(){
    cin >> n >> m;

    for(int i = 1; i <=n ;i++){
        for(int j =0; j <= m; j++)cin>>a[i][j];
    }
    //dp[val][pos] = val원을 썻을때 1~pos까지의 기업들만 투자했을 떄의 최대값
    // so.. answer is dp[n][m]
    // 테이블의 수 n*m , 각 테이블마다 점화식에 봐야하는 테이블의 수 n O(n^2*m)
    for(int pos = 1; pos <= m; pos++){
        for(int val = 1; val <= n; val++){
            for(int k = 0; k <=val; k++){//현재 기업에서 k원을 사용했을때
                int nval = a[k][pos]+dp[val-k][pos-1];
                if(nval>dp[val][pos]){
                    dp[val][pos] = nval;
                    btr[val][pos] = k;
                }
            }
        }
    }
    int r = n, c= m;
    cout << dp[r][c]<<"\n";
    while(r>0&&c>0){
        ans[c]=btr[r][c];
        r -= btr[r][c], c--;
    }
    for(int i = 1; i <=m; i++)cout <<ans[i]<<" ";
}