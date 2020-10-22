#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int MAX = 2e9;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int>v(n);
        for(int &i: v)cin>>i;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i : v)cout << i << " ";
        cout << "\n";
    }
}