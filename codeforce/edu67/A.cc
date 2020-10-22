#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int t,n,m;
int a[100001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        memset(a,0,sizeof(a));
        cin >> n;
        for(int i =0; i < n; i++){
            int k;
            cin >> k;
            a[k]++;
        }
        for(int i= 100000; i>=1; i--){
            a[i-1]+= a[i];
        }
        int ans = -1;
        for(int i = 0; i<= 99999; i++){
            if(a[i+1]>=2 && n-2>=i)ans=i; 
        }
        cout << ans << "\n";
    }
}