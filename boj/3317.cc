#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n ,m,k;
int f[100001];
int p[100001][32];
int Q(int s,int x){
    for(int i =30; i>=0;i--){
        if(x>=(1<<i)){
            x -= (1<<i);
            s=p[s][i];
        }
    }
    return s;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++)cin >> f[i];
    for(int i= 1; i <=m; i++)cin >> p[i][0];
    for(int i=1; i<=31;i++){
        for(int j =1; j <=m; j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    for(int i =1; i<=n; i++){
        cout << Q(f[i], k-1) << " ";
    }
}