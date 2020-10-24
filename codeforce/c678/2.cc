#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int a[101][101];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(a,0,sizeof(a));
        for(int i =0; i < n; i++){
            a[i][i]=1;
            a[i][n-i-1]=1;
        }
        if(n&1){
            a[n/2][n/2-1]=1;
            a[n/2-1][n/2]=1;
        }
        for(int i =0; i < n; i++){
            for(int j =0; j < n; j++){
                cout << a[i][j]<<" ";
            }
            cout << "\n";
        }
    }
}