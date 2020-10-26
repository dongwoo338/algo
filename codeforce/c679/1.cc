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
        vector<int>b(n);
        for(int &i:v)cin>>i;
        for(int i =0; i < n/2; i++){
            b[i]= -v[n-1-i];
            b[n-1-i]= v[i];
        }
        for(int x : b)cout << x<<" ";
        cout << "\n";
    }
    
}