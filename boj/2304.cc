#include<bits/stdc++.h>
using namespace std;
int a[1003],lmax[1003],rmax[1003];
int main(){
    int n;
    cin >> n;
    for(int i =0; i < n; i++){
        int l,h;
        cin >> l >> h;
        a[l]= h;
    }
    for(int i =0; i <= 1000; i++){
        if(i==0)lmax[i]=a[i];
        else lmax[i]=max(lmax[i-1],a[i]);
    }
    for (int i = 1000; i >= 0; i--){
        if(i==1000)rmax[i] = a[i];
        else rmax[i] = max(rmax[i+1],a[i]);
    }
    int ans=0;
    for(int i =0; i <= 1000; i++){
        ans += min(rmax[i],lmax[i]);
    }
    cout << ans;
}