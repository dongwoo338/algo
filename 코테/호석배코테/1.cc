#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int maxt(string s){
    int ret=0;
    for(char c : s)if((c-'0')&1)ret++;
    if(s.length()==1)return ret;
    if(s.length()==2){
        ret+=ret;
        return ret;
    }
    int tpl=0;
    for(int lo= 1; lo < s.length()-2; lo++){
        for(int hi = lo; hi < s.length() - 1; hi++){
            tpl = max(tpl,maxt(s.substr(0,lo))+maxt(s.substr(lo,hi-lo+1))+maxt(s.substr(hi,s.length()-hi+1)));
        }
    }
    ret += tpl;
    return ret;
}
int mint(string s){
    int ret=0;
    for(char c : s)if((c-'0')&1)ret++;
    if(s.length()==1)return ret;
    if(s.length()==2){
        ret+=ret;
        return ret;
    }
    int tpl=9999;
    for(int lo= 1; lo < s.length()-2; lo++){
        for(int hi = lo; hi < s.length() - 1; hi++){
            tpl = min(tpl,maxt(s.substr(0,lo))+maxt(s.substr(lo,hi-lo+1))+maxt(s.substr(hi,s.length()-hi+1)));
        }
    }
    ret += tpl;
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    cout << maxt(s)<<" "<<mint(s);
}