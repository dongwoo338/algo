#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int a[1001];
int dp[1001];
int n;
int rec(int x){
    int &ret =dp[x];
    if(ret !=-1)return ret;
    ret = a[x];
    int maxt =0 ;
    for(int i = x+ 1; i < n; i++){
        if(a[i]>a[x])maxt=max(maxt,rec(i)); 
    }
    ret += maxt;
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> v={0};
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i< n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int ans=0;
    for(int i=0; i <n; i++){
        ans=max(ans,rec(i));
    }
    cout << ans;
}