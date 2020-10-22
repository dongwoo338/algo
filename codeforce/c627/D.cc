#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
vector<int>diff;
int a[200001];
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i =0; i < n ; i++)cin>>a[i];
    for(int i =0; i < n ; i++){
        int k;
        cin >> k;
        diff.push_back(a[i]-k);
    }
    sort(diff.begin(),diff.end());
    for(int i =0; i < n ; i++){
        if(diff[i]<=0)continue;
        int pos = lower_bound(diff.begin(),diff.end(),-diff[i]+1)-diff.begin();
        ans+=(i-pos);
    }
    cout << ans;
}