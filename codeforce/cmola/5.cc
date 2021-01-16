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
        int n;
        cin >> n;
        vector<pair<pi,int>>a;// w h i
        vector<pair<pi,int>>b;// h w i
        vector<int>ans(n,-1);
        for(int i =0; i < n; i++){
            int w,h;
            cin >> w >> h;
            a.push_back({{min(w,h),max(w,h)},i});
            b.push_back({{h,w},i});
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<pi>tmp;
        int pval = MAX;
        int hmin = MAX;
        int hind = -1;
        for(int i =0; i < n; i++){
            auto &[nw,nh] =a[i].first;
            auto ni = a[i].second;
            if(pval<nw){
                for(auto &[val,ind] : tmp){
                    if(val<hmin){
                        hmin=val;
                        hind=ind;
                    }
                }
                tmp.clear();
            }
            if(hmin<nh){
                if(ans[ni]==-1)ans[ni]=hind;
            }
            tmp.push_back({nh,ni});
            pval = nw;
        }
        for(int i =0; i < n; i++){
            if(ans[i]==-1)cout<<-1<<" ";
            else cout << ans[i]+1 <<" ";
        }
        cout << "\n";
    }
}