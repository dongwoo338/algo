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
        int n,x;
        cin >> n >> x;
        vector<int>a(n),b(n);
        for(int &i:a)cin>>i;
        for(int &i:b)cin>>i;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());
        bool ispos= 1;
        for(int i =0; i <n ;i++){
            if(a[i]+b[i]>x)ispos=0;
        }
        if(ispos)cout<<"YES\n";
        else cout<<"NO\n";
    }
}