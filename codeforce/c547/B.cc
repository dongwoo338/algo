#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int a[400001];
int ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> a[i];
        a[i+n]=a[i];
    }
    int cnt=0;
    for(int i =0; i < 2 *n; i++){
        if(a[i])cnt++;
        else {
            ans = max(ans,cnt);
            cnt=0;
        }
    }
    cout << ans;
}