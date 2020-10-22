#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int dp[2001][2001];
int n,h,l,r;
int a[2001];
int rec(int i,int t){
    if(i>=n)return 0;
    int &ret = dp[i][t];
    if(ret!=-1)return ret;
    ret = 0;
    int fv =rec(i+1,(t+a[i])%h);
    if((t+a[i])%h >= l && (t+a[i])%h < r)fv++;
    ret = max(ret,fv);
    int sv =rec(i+1,(t+a[i]-1)%h);
    if((t+a[i]-1)%h >= l && (t+a[i]-1)%h < r)sv++;
    ret = max(ret,sv);
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> n >> h >> l >> r;
    cout << rec(0,0);
}