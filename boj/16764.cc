#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
map<long double,int>mp;
vector<int> v;
int a[5];
ll ans;
const long double dd = 1e6+1;
long double hval(){
    long double ret=0;
    for(int i=0; i < v.size(); i++){
        ret*=dd; ret+=(long double)v[i];
    }
    return ret;
}
void subset(int l =-1){
    long double dv = hval();
    if(v.size())ans += (v.size()&1 ? 1LL : -1LL)*mp[dv]++;
    for(int i = l + 1; i < 5; ++i){
        v.push_back(a[i]);
        subset(i);
        v.pop_back();
    }
}
int main(){
    int n;
    cin >> n;
    for(int i =0; i < n; i++){
        for(int j=0; j < 5; j++)cin >> a[j];
        sort(a,a+5);
        v.clear();
        subset();
    }
    cout << 1ll * n * (n - 1) / 2 - ans;
}