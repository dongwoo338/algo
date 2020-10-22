#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int t,n,m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin>>n>>m;
        vector<int>a(n);
        for(int&i:a)cin>>i;
        vector<int>p(n);
        for(int i=0; i <m ; i++){
            int pos;
            cin >> pos;
            p[pos-1]=1;
        }
        bool isok =1;
        while(1){
            bool isc=0;
            for(int i=0; i < n- 1; i++){
                if(p[i]&&a[i]>a[i+1]){
                    swap(a[i],a[i+1]);
                    isc=1;
                }
                if(!p[i]&&a[i]>a[i+1]){
                    isok=0;
                    break;
                }
            }
            if(!isc)break;
        }
        cout << (isok ? "YES\n":"NO\n");
    }
}