// maybe sparse table??
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n ,m,k;
int p[100001][31];
int Q(int s,int x){
    for(int i = 30; i >=0; i--){
        if(x>=(1<<i)){
            s = p[s][i];
            x -= (1<<i);
        }
    }
    return s;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >>k;
    for(int i = 1; i <=n; i++)p[i][0]=i;
    for(int i =0; i < m; i++){
        int s,e;
        cin >> s >> e;
        for(int j=0;j < (e+1-s)/2; j++){
            swap(p[s+j][0],p[e-j][0]);
        }
    }
    for(int i = 1; i <= 30; i++){
        for(int j =1; j <= n; j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    for(int i =1; i<=n;i++){
        cout << Q(i,k) << "\n";
    }
}