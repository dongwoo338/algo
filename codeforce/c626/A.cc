#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int MAX = 2e9;
int t, n,m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n%m)cout <<"NO"<<"\n";
        else cout << "YES" <<"\n";
    }
}