#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n;
set<int>s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i =1; i <= n; i++)s.insert(i);
    int pc=0;
    bool ispos=1;
    vector<int>ans;
    deque<int> dq;
    for(int i =0; i < 2 * n; i++){
        char c;
        int x;\
        cin >> c;
        if(c=='+'){
            pc++;
            if(dq.empty()){
                auto nl = prev(s.end());
                dq.push_front(*nl);
                s.erase(nl);
            }
            else{
                auto nl = prev(s.end());
                if(*nl<dq.front()){
                    dq.push_front(*nl);
                    s.erase(nl);
                }
                else{
                    dq.push_back(*nl);
                    s.erase(nl);
                }
            }
        }
        else{
            cin >> x;
            if(dq.empty()){
                ispos=0;
                break;
            }
            if(dq.front()==x){
                ans.push_back(x);
                dq.pop_front();
            }
            else{
                if(pc==n){
                    ispos=0;
                    break;
                }
                else if(x < dq.front()){
                    ans.push_back(x);
                    s.insert(dq.front());
                    dq.pop_front();
                }
                else{
                    ispos=0;
                    break;
                }
            }
        }
    }
    if(!ispos)cout<<"NO";
    else{
        cout<<"YES\n";
        for(int i : ans )cout <<i<<" ";
    }
}