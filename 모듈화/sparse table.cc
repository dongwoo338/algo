#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n ,m,k;
const int N =1e5+1;
const int LN = 17;
int p[N][LN];
int Q(int s,int x){
    for(int i =LN-1; i>=0;i--){
        if(x>=(1<<i)){
            x -= (1<<i);
            s=p[s][i];
        }
    }
    return s;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i= 1; i <=n; i++)cin >> p[i][0];
    for(int i=1; i<=LN;i++){
        for(int j =1; j <=N; j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
}