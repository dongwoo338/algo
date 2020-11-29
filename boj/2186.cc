#include<bits/stdc++.h>
using namespace std;
string s;
int n ,m,k;
char c[101][101];
int dp[101][101][88];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int rec(int x,int y,int p){
    int &ret = dp[x][y][p];
    if(ret !=-1)return ret;
    if(p==s.length()-1){
        ret= 1;
        return ret;
    }
    ret =0;
    for(int i=0; i <4; i++){
        for(int j = 1; j <= k; j++){
        int dx =x+dir[i][0]*j;
        int dy =y+dir[i][1]*j;
        if(dx<0||dx>=n||dy<0||dy>=m)continue;
        if(c[dx][dy]==s[p+1]){
            ret += rec(dx,dy,p+1);
        }
        }
    }
    return ret;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        string ss;
        cin >> ss;
        for(int j =0; j < m ; j++){
            c[i][j]= ss[j];
        }
    }
    cin >> s;
    int ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i =0; i < n; i++){
        for(int j =0; j < m; j++){
            if(c[i][j]==s[0])ans += rec(i,j,0);
        }
    }
    cout << ans;
}