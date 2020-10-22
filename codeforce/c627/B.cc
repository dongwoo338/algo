#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int a[5001];
        bool isok=0;
        memset(a,-1,sizeof(a));
        for(int i =0; i < n ; i++){
            int k;
            cin >> k;
            if(a[k]==-1)a[k]=i;
            else{
                if(i - a[k]>=2)isok=1;
            }
        }
        if(isok)cout<<"YES"<<"\n";
        else cout << "NO"<<"\n";
    }
}