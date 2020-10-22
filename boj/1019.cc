#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
ll a[10];
int n;
void zton(int fi,int suc){
    for(int i=0;i <=9; i++){
        a[i]+=(int)pow(10,suc-1);
    }
    if(fi==0)a[0]-=(int)pow(10, suc - 2);
}
void suc(int n){
    if(n>=0&&n<=9){
        for(int i=0;i<=n; i++)a[i]++;
        return;
    }
    int zar = floor(log10(n));
    int fn = n / (int)(pow(10,zar));
    for(int i=0; i < fn; i++){
        zton(i,zar);
    }
    n %= (int)(pow(10,zar));
    a[fn]+=(n+1);
    suc(n);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    suc(n);
    for(int i=0; i<=9; i++)cout <<a[i]<<" ";
}