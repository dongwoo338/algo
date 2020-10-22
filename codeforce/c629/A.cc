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
        cin >> n;
        int ans[1001];
        map<int,int> mp;// num col
        int cn=1;
        for(int i =0; i < n; i++){
            int k;
            cin >> k;
            for(int j = 2; j*j <= i; j++){
                if(k%j==0){
                    int nowc=0;
                    if(mp.count(j)==0){
                        mp[j]=cn++;
                        nowc=cn-1;
                    }
                    else nowc = mp[j];
                    ans[i] = nowc;
                    break;
                }
            }
        }
        cout << cn-1<< "\n";
        for(int i =0; i <n; i++)cout <<ans[i]<<" ";
        cout << "\n";
    }
}