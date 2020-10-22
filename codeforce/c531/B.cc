#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int b[5001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    vector<vector<int>>va(n+1);
    set<int> s;
    bool ispos=1;
    int c=1;
    for(int i=0; i < n; i++){
        int tm;
        cin >> tm;
        s.insert(tm);
        va[tm].push_back(i);
    }
    for(int i =1; i <=k; i++){
        if(va[i].size>k)ispos=0;
        for(int j : va[i]){
            b[j] = c++;
            c%=k;
        }
    }
    for(int i =1; i <= n; i++)cout << b[i] <<  " ";
}