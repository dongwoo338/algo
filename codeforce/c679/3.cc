#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int a[7];
int mina[7];
int n;
int b[100005];
int c[100005][7];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i =1; i <= 6; i++)cin >> a[i];
    for(int i =1; i <= 6; i++)mina[i]=(int)2e9;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> b[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(b[i]-a[j]>=0){
                c[i][j] = b[i]-a[j];
            }
            cout << c[i][j]<<" ";
        }
    }
}