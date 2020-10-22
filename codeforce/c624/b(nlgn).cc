#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int t,n,m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin>>n>>m;
        vector<int>a(n);
        for(int&i:a)cin>>i;
        vector<int>p(n);
        for(int i=0; i <m ; i++){
            int pos;
            cin >> pos;
            p[pos-1]=1;
        }
        
        cout << (isok ? "YES\n":"NO\n");
    }
}