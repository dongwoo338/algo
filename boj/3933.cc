#include<bits/stdc++.h>
using namespace std;
int dp[32780][4];
int zeg[1234];
int n;
int rec(int n,int c){
    if(c<0||n<0)return 0;
    if(n==0)return 1;
    int &ret = dp[n][c];
    if(ret != -1)return ret;
    ret =0;
    for(int i= 1; n-zeg[i]>=0;i++){
        ret += rec(n -zeg[i], c-1);
    }
    return ret;
}
int main(){
    for(int i = 1; i*i<=32779; i++)zeg[i]=i*i;
    memset(dp,-1,sizeof(dp));
    while(1){
        cin >> n;
        if(!n)break;
        cout << rec(n,3) <<"\n";
    }
}