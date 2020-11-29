// 22 - 4.2
// 임의의 DAG에서 시작정점 s와 도착정점 t를 입력으로 받아서
// 시작정점이 s이고 끝 정점이 t인 단순 경로의 개수를 return
// input:
  // n(max 1000),m, adjacent list, s, t
// output:
  /*
    단순 경로의 개수
  */

 #include<bits/stdc++.h>
 using namespace std;
 int n , m;
 int s,t;
 vector<vector<int>>g;
 const int N = 1001;
 int dp[N]; // i - >t까지의 단순 경로의 개수
 int rec(int u){
     int &ret= dp[u];
     if(ret!=-1)return ret;
     ret= 0;
     if(u==t)ret=1;
     else{
         for(auto &v : g[u]){
             ret += rec(v);
         }
     }
     return ret;
 }
 int main(){
     cin >> n >> m;
     g.resize(n+1);
     for(int u,v; m--;){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
     }
     cin >> s >> t;
     memset(dp,-1,sizeof(dp));
     cout << rec(s);
 }