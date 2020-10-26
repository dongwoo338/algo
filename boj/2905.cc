#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n ,x;
const int N = 1000005;
ll a[N],pa[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pa[i]= pa[i-1]+a[i];
    }
    
}