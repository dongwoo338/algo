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
    string s;
    cin >> s;
    string s1="";
    string s2="";
    for(int i=0; i < s.length(); i++){
        if(i&1){
            s1+='1';
            s2+='0';
        }
        else{
            s1+='0';
            s2+='1';
        }
    }
    int an1=0, an2=0;
    for(int i =0; i < s.length(); ){
        if(s[i]==s1[i]){
            i++;
            continue;
        }
        else{
            while(i<s.length()&&s[i]!=s1[i])i++;
            an1++;
        }
    }
        for(int i=0; i < s.length(); i++){
        if(i&1){
            s1+='1';
            s2+='0';
        }
        else{
            s1+='0';
            s2+='1';
        }
    }
    for(int i =0; i < s.length(); ){
        if(s[i]==s2[i]){
            i++;
            continue;
        }
        else{
            while(i<s.length()&&s[i]!=s2[i])i++;
            an2++;
        }
    }
    cout << min(an1,an2)<<"\n";
    }
}