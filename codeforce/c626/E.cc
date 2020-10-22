#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for(int i =0; i < n; i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    for(int i = 1; i <= 1000; i++){
        for(int j=0; j < v.size(); j++){
            if(j==0||j==v.size()-1)continue;
            
        }
    }
}