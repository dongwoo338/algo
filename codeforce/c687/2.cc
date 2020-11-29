#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int>v(n);
        for(int &i:v)cin>>i;
        int ans=(int)1e9;
        for(int i = 1; i <= 100; i++){
            int j=0;
            int cnt=0;
            while(j<n){
                if(v[j]!=i){
                    j+=k;
                    cnt++;
                }
                else j++;
            }
            ans =min(ans,cnt);
        }
        cout << ans << "\n";
    }
}