#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,a,b;
    cin >> t;
    while(t--){
        int x=0;
        cin >> a >> b;
        for(int i =30; i >=0; i--){
            int cnt=0;
            if(a&(1<<i))cnt++;
            if(b&(1<<i))cnt++;
            if(cnt!=0)x|=(1<<i);
        }
        int ans =(a^x)+(b^x);
        cout << ans << "\n";
    }
}