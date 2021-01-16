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
        vector<int>a(n);
        for(int &i:a)cin>>i;
        sort(a.begin(),a.end());
        int mind = a[0]+a[1];
        if(mind>m && a[n-1]>m)cout<<"NO\n";
        else cout<<"YES\n";
    }
}