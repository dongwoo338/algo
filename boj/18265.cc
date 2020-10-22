#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
ll n;
ll mid;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    int now = 0;
    for(int i=30; i>=0; i--){
        int ne = now+(1<<i);
        int val = ne -(ne/3)-(ne/5)+(ne/15);
        if(n>=val)now = ne;
    }
    while((now%3)==0||(now%5)==0)now--;
    cout<< now;
}