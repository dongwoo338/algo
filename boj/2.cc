#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 1;
typedef pair<int, int> pi;
int t, n;
int g[MAX];
int b[MAX];
int fan,san;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        bool isimp=0;
        for (int i = 1; i <= n; i++)g[i] = b[i] = 0;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int bn;
                cin >> bn;
                if (g[i] == 0 && b[bn] == 0) {
                    b[bn] = i;
                    g[i] = 1;
                }
            }
        }
        for(int i =1; i <= n; i++)if(b[i] ==0){
            for(int j = 1; j <= n; j++){
                if(g[j]==0){
                    fan = j; san = i;
                    isimp=1;
                    break;
                }
            }
            if(isimp)break;
        }
        if(isimp){
            cout<<"IMPROVE"<<"\n";
            cout<<fan<<" "<<san<<"\n";
        }
        else{
            cout<<"OPTIMAL"<<"\n";
        }
    }
}