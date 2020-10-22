#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==1)cout << -1<<"\n";
        else{
            vector<int>ans;
            ll sums=0;
            for(int i=0; i< n - 1; i++){
                sums += 2;
                ans.push_back(2);
            }
            if(sums%9==0)ans[n-2]++;
            ans.push_back(9);
            for(int i : ans)cout<<i;
            cout << "\n";
        }
    }
}