#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    vector<int>primes;
    for(int i = 2;primes.size()<=101; i++){
        bool isp=1;
        for(int j =2; j*j<=i; j++){
            if(i%j==0){
                isp=0;
                break;
            }
        }
        if(isp)primes.push_back(i);
    }
    while(t--){
        int n;
        cin >> n;
        for(int i =0; i < n; i++){
            cout << 2*primes[i]<<" ";
        }
        cout << "\n";
    }
}