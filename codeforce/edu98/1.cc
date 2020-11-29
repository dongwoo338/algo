#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int ans=0;
        if(a>b)swap(a,b);
        int mint =min(a,b);
        ans += mint*2;
        a-=mint, b-=mint;
        if(b)ans += (2*b-1);
        cout << ans << "\n";
    }
}