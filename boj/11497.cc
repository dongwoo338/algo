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
        vector<int>v(n);
        for(int &i : v)cin >> i;
        sort(v.begin(),v.end());
        vector<int>a(n);
        int j=0;
        for(int i =0; i < n; i+=2){
            a[j++]=v[i];
        }
        int i = ((n&1) ? n -2 : n -1);
        while(i>=0){
            a[j++]=v[i];
            i-=2;
        }
        int ans= a[n-1]-a[0];
        for(int i =1; i < n; i++)ans=max(ans,abs(a[i]-a[i-1]));
        cout << ans <<"\n";
    }
}