#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
vector<int> v;
int n,x;
const int MOD =(int)1e9+7;
int main(){
    cin >> n >> x;
    for(int i= 0; i < n; i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    //sort(v.begin(),v.end());
    dp[0]=1;
    for(int i =0; i < n; i++){
        for(int j =0; j <= x; j++){
            if(j-v[i]>=0)dp[j]= (dp[j] + dp[j - v[i]])%MOD;
        }
    }
    cout << dp[x];
}