#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int a[4];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map<pi,int>mp;
    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        int x,y;
        cin >> x >> y;
        if(x==0|| y==0){
            if(x==0){
                if(y>0)a[0]++;
                else a[1]++;
            }
            else if(y==0){
                if(x>0)a[2]++;
                else a[3]++;
            }
            continue;
        }
        int buho = 0;
        if(x<0&&y<0)buho=1;
        if(x<0&&y>0)buho=2;
        if(x>0&&y<0)buho=3;
        x=abs(x); y= abs(y);
        int G = gcd(x,y);
        x/=G, y/=G;
        if(buho==1){
            x*=-1, y*=-1;
        }
        if(buho==2)x*=-1;
        if(buho==3)y*=-1;
        mp[{x,y}]++;
    }
    int ans=0;
    for(int i =0; i < 4; i++)ans=max(ans,a[i]);
    for(auto k : mp)ans=max(ans,k.second);
    cout << ans;
}