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
        int n ,k;
        cin >> n >> k;
        string a,b;
        cin >> a >> b;
        vector<int>ac(26),bc(26);
        for(char c: a)ac[c-'a']++;
        for(char c: b)bc[c-'a']++;
        bool isok=1;
        for(int i =0; i < 26 ;i++){
            if(i!=0)ac[i]+=ac[i-1];
            if(ac[i]<bc[i]||(ac[i]-=bc[i])%k)isok=0;
        }
        if(isok)cout<<"YES\n";
        else cout <<"NO\n";
    }
}