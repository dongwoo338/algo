#include<bits/stdc++.h>
using namespace std;
int a[500002];
long long ans;
int main(){
    int n;
    cin >> n;
    for(int i= 1; i <= n; i++)cin>> a[i];
    sort(a+1,a+1+n);
    for(int i = 1; i <= n; i++){
        ans+=abs(a[i]-i);
    }
    cout << ans;
}