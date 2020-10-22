#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int a[52][52];
int b[52][52];
int t,n,m;
void solv(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int acnt =0, bcnt=0;
    cin >> n >> m;
    for(int i =0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> a[i][j];
            acnt += a[i][j];
        }
    }
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            if(b[i][j]==0&&a[i][j]==1){
                b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
            }
        }
    }
    for(int i=0; i < n; i++){
        for(int j =0; j < m; j++){
            bcnt+=b[i][j];
        }
    }
    if(acnt==bcnt)cout<<"YES"<<"\n";
    else cout << "NO"<< "\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)solv();
}