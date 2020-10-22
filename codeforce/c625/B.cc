#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int a[40001];
int b[40001];
int n , m , k;
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0 ; i < n ; i++)cin >> a[i];
    for(int i=0 ; i < m ; i++)cin >> b[i];
    for(int i = 1;i < n; i++){
        if(a[i])a[i] = a[i-1]+1;
    }
    for(int i =1; i < m; i++){
        if(b[i])b[i] = b[i - 1] + 1;
    }
    for(int i=1;i*i<=k; i++){
        if(k%i)continue;
        int ln = i, rn = k/i;
        int lcnt=0,rcnt=0;
        for(int i=0; i <n ;i++)if(a[i]>=ln)lcnt++;
        for(int i=0; i <m ;i++)if(b[i]>=rn)rcnt++;
        ans += (ll)lcnt*(ll)rcnt;
        if(ln==rn)continue;
        swap(ln,rn);
        lcnt=0,rcnt=0;
        for(int i=0; i <n ;i++)if(a[i]>=ln)lcnt++;
        for(int i=0; i <m ;i++)if(b[i]>=rn)rcnt++;
        ans += (ll)lcnt*(ll)rcnt;
    }
    cout << ans;
}