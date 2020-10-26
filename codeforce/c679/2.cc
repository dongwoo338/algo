#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int a[501][501];
int b[501][501];
int c[501][501];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)cin >> a[i][j];
        }
        map<int,int>mp;// elem,rownum
        for(int i = 1; i <= n; i++){
            mp[a[i][1]]=i;
        }
        for(int i = 1; i <=m; i++){
            for(int j  =1 ; j <= n; j++){
                cin >> c[i][j];
            }
        }
        vector<int> vt;// ㄱ의 순서
        for(int i = 1; i <= m; i++){
            if(!mp.count(c[i][1]))continue;
            for(int j=1; j <= n; j++){
                vt.push_back(mp[c[i][j]]);
            }
        }
        int rn = 1;
        for(int i : vt){
            for(int j =1; j <= m; j++)b[rn][j]=a[i][j];
            rn++;
        }
        for (int i =1; i <=n; i++){
            for(int j = 1; j <=m; j++){
                cout << b[i][j]<<" ";;
            }
            cout << "\n";
        }
    }
}