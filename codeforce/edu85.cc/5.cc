#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int a[101], b[101];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i <n; i++)cin >> a[i] >> b[i];
        bool ispos=1;
        for(int i =0; i < n; i++)if(a[i]<b[i])ispos=0;
        for(int i =1; i < n; i++){
            int ac= a[i] - a[i-1];
            int bc= b[i] - b[i-1];
            if(ac <0 || bc < 0)ispos=0;
            if(ac==0&&bc>0)ispos=0;
        }
        if(ispos)cout<<"YES"<<"\n";
        else cout << "NO"<<"\n";
   }
}