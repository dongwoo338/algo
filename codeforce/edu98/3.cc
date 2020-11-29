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
        stack<char>s1,s2;
        int ans =0 ;
        for(char c :s){
            if(c==')'){
                if(s1.size()){
                    s1.pop();
                    ans++;
                }
            }
            if(c=='(')s1.push(c);
            if(c==']'){
                if(s2.size()){
                    s2.pop();
                    ans++;
                }
            }
            if(c=='['){
                s2.push(c);
            }
        }
        cout << ans << "\n";
    }
}