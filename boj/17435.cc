#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int p[500001][21];
int n,m;
int Q(int x,int s){
    for(int i = 20; i >=0;i--){
        if(x >= (1<<i)){
            x -= (1<<i);
            s = p[s][i];
        }
    }
    return s;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i =1; i <= n; i++)cin>>p[i][0];
    for(int i = 1; i <= 20; i++){
        for(int j =1; j <= n; j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    cin >> m;
    for(int i =0; i < m; i++){
        int s,x;
        cin >> x >> s;
        cout << Q(x,s)<<"\n";
    }
}