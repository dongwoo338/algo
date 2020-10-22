#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a, b;
    cin >> a >> b;
    if(a==0&&b==0){
        cout << 0;
        return 0;
    }
    if(a<b||(b-a)&1){
        cout << -1;
        return 0;
    }
    
}