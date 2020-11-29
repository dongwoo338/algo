#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n;
int a[101][101];
int dir[4][2] ={{-1,0},{0,1},{1,0},{0,-1}};
int c[101][101][5][21];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i<= n;i++){
        for(int j = 1; j<=n; j++)cin >> a[i][j];
    }
    queue<pair<pi,pi>>q;
    memset(c,-1,sizeof(c));
    c[1][1][4][0]= 0;
    q.push({{1,1},{4,0}});
    int ans =(int)1e9;
    while(q.size()){
        auto [x,y] = q.front().first;
        auto [d,v] = q.front().second;
        int t = c[x][y][d][v];
        q.pop();
        for(int i=0; i <4; i++){
            int dx,dy,dd,dv;
            if(i==d)dv=v+1;
            else dv = 1;
            dx = x + dv*dir[i][0];
            dy = y + dv*dir[i][1];
            if(dx <= 0 || dy <= 0 || dx >n || dy > n)continue;
            if(a[dx][dy] > t + 1&&c[dx][dy][i][dv]==-1){
                c[dx][dy][i][dv] = t + 1;
                if(dx==n&&dy==n)ans=min(ans,t+1);
                q.push({{dx,dy},{i,dv}});
            }
        }
    }
    if(ans==1e9)cout<<"Fired";
    else cout << ans;
}