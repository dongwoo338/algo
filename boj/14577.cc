#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
ll seg[400001];
int n,k;
int tsiz = 1;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    while(tsiz<n)tsiz*=2;
    for(int i=0; i < n; i++){
        cin >> seg[tsiz+i-1];
    }
    for(int i = tsiz - 1; i >= 1; i--){
        seg[i] = seg[i*2]+seg[i*2+1];
    }
    
}