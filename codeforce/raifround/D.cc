#include<bits/stdc++.h>
using namespace std;
const int N= (int)1e5+5;
int a[N];
typedef pair<int,int> pi;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    bool ispos=1;
    int rr = n;
    vector<pi>vf,vs,ans; // r,c
    for(int i = n; i >= 1; i--){
        if(a[i]==0)continue;
        if(a[i]==1){
            ans.push_back({rr,i});
            vf.push_back({rr--,i});
        }
        else if(a[i]==2){
            if(vf.empty()){
                ispos=0;break;
            }
            ans.push_back({vf.back().first,i});
            vs.push_back(ans.back());
            vf.pop_back();
        }
        else{
            if(vf.empty()&&vs.empty()){
                ispos=0;break;
            }
            else if(vs.size()){
                ans.push_back({rr,vs.back().second});
                ans.push_back({rr--,i});
                int tmp=vs.back().first;
                vs.pop_back();
                vs.push_back({tmp,i});
            }
            else{
                ans.push_back({rr,vf.back().second});
                ans.push_back({rr,i});
                int tmp = vf.back().first;
                rr--;
                vf.pop_back();
                vs.push_back({tmp,i});
            }
        }
    }
    if(!ispos){
        cout << -1;
        return 0;
    }
    cout << ans.size()<<"\n";
    for(auto &[x,y] : ans){
        cout << x<<" "<<y<<"\n";
    }
}