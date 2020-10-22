#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int mlen = s.length()+1;
        vector<int>v;
        deque<int> dq;
        for(int i=0; i < s.length(); i++){
            if(s[i] == 'R')dq.push_back(i+1);
        }
        dq.push_front(0);
        dq.push_back(mlen);
        bool isfir=1;
        int pren=0;
        int ans = 0;
        while(!dq.empty()){
            if(isfir){
                isfir=0;
                pren=dq.front();
                dq.pop_front();
                continue;
            }
            ans=max(ans,dq.front()-pren);
            pren=dq.front();
            dq.pop_front();
        }
        cout<<ans<<"\n";
    }
}