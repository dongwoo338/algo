#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int t,n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        set<int> s;
        cin >> n;
        for(int i=0; i < n; i++){
            int k;
            cin >> k;
            s.insert(k);
        }
        cout << s.size() << "\n";
    }
}