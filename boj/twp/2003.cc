#include<bits/stdc++.h>
using namespace std;
int n, m,ans;
const int N = 10001;
int a[N];
int ps= 0;// 현재 [lo~hi]구간 사이의 합
int main(){
    cin >> n>> m;
    int lo=0, hi =0;
    while(hi<n){
        if(ps>=m)ps+=a[hi++];
        else ps -= a[++lo];
        if(ps==m)ans++;
    }
    cout << ans;
}