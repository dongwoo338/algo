#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int t,n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        int ocnt=0;
        int ecnt=0;
        int n;
        cin >> n;
        for(int i =0; i < n ;i++){
            int tt;
            cin >> tt;
            if(tt%2)ocnt++;
            else ecnt++;
        }
        if(ocnt&&ecnt==0)cout<<"YES"<<"\n";
        else if(ecnt&&ocnt==0)cout<<"YES"<<"\n";
        else cout << "NO"<<"\n";
    }
}