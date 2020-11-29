#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
ll dp[31][31];
int s,e;
ll rec(int x,int y){
    ll &ret= dp[x][y];
    if(y>x)return 0;
    if(x==e&&y==e)return 1;
    if(ret!=-1)return ret;
    ret= 0;
    if(s>e){
        for(int i =0 ; i < 2; i++){
            int dx =x, dy =y;
            if(i==0)dx--;
            else dy--;
            if(dx<e||dy<e)continue;
            ret += rec(dx,dy); 
        }
    }
    else{
        for(int i =0; i < 2; i++){
            int dx=x, dy= y;
            if(i==0)dx++;
            else dy++;
            if(dx>e||dy>e)continue;
            ret += rec(dx,dy);
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s >> e;
    memset(dp,-1,sizeof(dp));
    if(s==e)cout<<1;
    else cout << rec(s,s);
}