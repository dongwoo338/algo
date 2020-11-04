#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int a[51], pa[51];
bool pre[1055][2555];//pre now
bool now[1055][2555];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i =1; i <=n ; i++){
        cin >> a[i];
        pa[i]=pa[i-1]+a[i];
    }
    pre[0][0]=1;
    for(int i = 1; i <=n; i++){
        memset(now,0,sizeof(now));   
        for(int l = 0; l <= 50*i; l++){
            for(int r = 0; r <= 50*i; r++){
                if(pre[l][r]){
                    if(l+a[i]<=1000)now[l+a[i]][r]=1;
                    now[l][r+a[i]]=1;
                }
            }
        }
        for(int l =0; l <=50*i+50; l++){
            for(int r= 0; r <= 50*i+50; r++){
                pre[l][r]=now[l][r];
            }
        }
    }
    int ans=0;
    for(int i=0; i<= 1000; i++){
        for(int j =0; j <= 2500; j++){
            if(i <=j && (i<=pa[n]-i-j)){
                if(pre[i][j])ans=max(i,ans);
            }
        }
    }
    cout << ans;
}