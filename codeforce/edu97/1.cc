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
        if(b/2<a)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}