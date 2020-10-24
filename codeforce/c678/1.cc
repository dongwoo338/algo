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
        int n,m;
        cin >> n >> m;
        vector<int>v(n);
        int ps=0;
        for(int &i :v){
            cin >> i;
            ps+=i;
        }
        if(ps==m)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}