#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,sums;
int main(){
    cin >> n >> k;
    vector<int>v(n);
    for(int &i:v)cin>>i;
    int lo=0;
    for(int i =0; i < n; i++){
        sums += v[i];
        while(sums > k)sums-=v[lo++];
        if(sums==k)cnt++;
    }
    cout << cnt;
}