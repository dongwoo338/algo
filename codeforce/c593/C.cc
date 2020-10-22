#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>>v(n);
    for(int i =0; i < n*n; i++){
        int dn= (i%(2*n));
        if(dn>=n) v[n-1-(i%n)].push_back(i+1);
        else v[i%n].push_back(i+1);
    }
    for(auto i : v){
        for(auto j : i)cout <<j<< " ";
        cout << "\n";
    }
}