#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,a,b,c,d,e;
    cin >> t;
    while(t--){
        int ans= 0;
        cin >> a >> b >> c;
        a/=2;
        if(d<=e){
            while(a&&c){
                ans += e;
                a--; c--;
            }
            while(a&&b){
                ans += d;
                a--; b--;
            }
        }
        else{
            while(a&&b){
                ans += d;
                a--; b--;
            }
            while(a&&c){
                ans += e;
                a--; c--;
            }
        }
        cout << ans << "\n";
    }
}