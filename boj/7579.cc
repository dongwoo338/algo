#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int dp[10001];
int n,x;
int sm;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    vector<pi> v(n);
    for(auto &i: v)cin >> i.second;
    for(auto &i: v)cin >> i.first;
    sort(v.begin(),v.end());
    for(auto i : v){
        for(int j =10000; j >=0; j--){
            if(j+i.first <= 10000){
                dp[j+i.first]= max(dp[j+i.first], dp[j]+i.second);
            }
        }
    }
    for(int i= 0; i <=10000;i++){
        if(dp[i]>=x){
            cout << i;
            break;
        }
    }
}