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
        int n;
        cin >> n;
        if(n<=3){
            cout << n -1<<"\n";
        }
        else if(n&1){
            cout << 3 << "\n";
        }
        else cout << 2 << "\n";
    }
}