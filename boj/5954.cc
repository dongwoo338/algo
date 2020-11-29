#include<bits/stdc++.h>
using namespace std;
// diff a, b
int pre[4004],now[4004];
bool ispos[4004];
int main(){
    const int MOD = (int)1e6;
    int n;
    cin >> n;
    pre[2000]=1;
    for(int i=0 ; i < n; i++){
        int x;
        //cin >> x;
        x=1;
        memset(now,0,sizeof(now));
        
        for(int j =0; j <= 4000; j++){
            if(!pre[j])continue;
            if(j+x<=4000){
                now[j+x]=(now[j+x]+pre[j])%MOD;
                if(i==n-1)ispos[j+x]=1;
            }
            if(j-x>=0){
                now[j-x] = (now[j-x]+pre[j])%MOD;
                if(i==n-1)ispos[j-x]=1;
            }
        }
        for(int j =0; j <= 4000; j++)pre[j]=now[j];
    }
    for(int i =0; i <= 2000; i++){
        if(ispos[2000+i]){
            cout <<i <<"\n";
            cout << pre[2000+i]%MOD<<"\n";
            break;
        }       
    }
}