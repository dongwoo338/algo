#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int a[51][51];
int b[51][51];
int ocnt;
int bcnt;
vector<pair<int,int>>anv;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i =0; i < n; i++){
        for(int j =0; j < m; j++){
            cin >> a[i][j];
            ocnt += a[i][j];
        }
    }
    for(int i=0; i < n -1; i++){
        for(int j= 0; j < m - 1; j++){
            if(a[i][j]&&a[i][j+1]&&a[i+1][j]&&a[i+1][j+1]){
                anv.push_back({i,j});
                b[i][j]=1;
                b[i+1][j]=1;
                b[i][j+1]=1;
                b[i+1][j+1]=1;
            }
        }
    }
    for(int i= 0; i < n ; i++){
        for(int j =0; j < m; j++){
            bcnt+=b[i][j];
        }
    }
    if(ocnt==bcnt){
        cout << anv.size()<<"\n";
        for(auto i : anv)cout << i.first+1 << " "<< i.second+1 << "\n";
    }
    else cout << -1;
}