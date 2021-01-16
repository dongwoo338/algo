#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int gcd(int a, int b){
    
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a,b;cin >> a >> b;
        int la= a.length(), lb = b.length();
        string ta ="";
        string tb ="";
        int lcm = la*lb/gcd(la,lb);
        la = lcm/la;
        lb = lcm/lb;
        while(la--)ta+=a;
        while(lb--)tb+=b;
        if(ta!=tb)cout<<-1<<"\n";
        else  cout <<ta<<"\n";
    }
}