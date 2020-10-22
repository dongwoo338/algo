#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int a,b;
int ans = -1;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> a >> b;
    if(b%a==0){
        b/=a;
        ans=0;
        while(b>1){
            if(b%2==0){
                b/=2;
                ans++;
            }
            else if(b%3==0){
                b/=3;
                ans++;
            }
            else {
                ans=-1;
                break;
            }
        }
    }
    cout << ans;
}