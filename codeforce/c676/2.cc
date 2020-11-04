#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
char c[501][501];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        for(int i =0; i <n; i++){
            string s;
            cin >> s;
            for(int j =0; j < n; j++)c[i][j] =s[j];
        }
        vector<pi> v= {{0,1},{1,0},{n-1,n-2},{n-2,n-1}};
        vector<pi>ans;
        for(int i =0; i <4; i++){
            auto &[x,y] = v[i];
            if(i<2){
                if(c[x][y] =='0')ans.push_back({x,y});
            }
            else{
                if(c[x][y]=='1')ans.push_back({x,y});
            }
        }
        if(ans.size()<=2){
            cout << ans.size()<<"\n";
            for(auto &[x,y]:ans)cout<<x+1<<" "<<y+1<<"\n";
            continue;
        }
        ans.clear();
            for(int i =0; i <4; i++){
            auto &[x,y] = v[i];
            if(i<2){
                if(c[x][y] =='1')ans.push_back({x,y});
            }
            else{
                if(c[x][y]=='0')ans.push_back({x,y});
            }
        }
        if(ans.size()<=2){
            cout << ans.size()<<"\n";
            for(auto &[x,y]:ans)cout<<x+1<<" "<<y+1<<"\n";
            continue;
        }
    }
}