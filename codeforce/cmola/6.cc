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
        int n , m;
        cin >> n >> m;
        map<int,int>mp;
        bool ispos = 1;
        for(int i=0; i < m; i++){
            int x,y;
            cin >> x >> y;
            if(mp.count(y)){
                if(x==2)mp[y]++;
                else mp[y]+=2;
            }
            else{
                if(x==2)mp[y]=1;
                else mp[y]=2;
            }
        }
        int stat=0;
        for(auto& [x,y] : mp){
            if(y==3){
                if(stat!=0){
                    ispos=0;
                    break;
                }               
            }
            if(y==1){
                if(stat==0){
                    stat=1;
                }
            }
        }
        if(ispos&&stat==0)cout<<"YES\n";
        else cout <<"NO\n";
    }
}