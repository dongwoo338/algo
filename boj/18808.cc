#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int f[51][51];
int rf[51][51];
int dix[4] ={-1,0,1,0};
int dly[4] ={0,1,0,-1};
int n , m, g, r, rans;
int gsz;// sizeof ground
vector<pi>gvt;//ground vector
vector<int>gperv;// ground permutation vector
void bfs(vector<pi> &gs,vector<pi> &rs){
    int ans =0;
    for(int i=0; i < n; i++)
        for(int j =0; j < m; j++)rf[i][j] = (f[i][j]==0 ? 1 : 0);
    queue<pi> gq;
    queue<pi> rq;
    for(auto i : gs) gq.push(i);
    for(auto i : rs) rq.push(i);
    while(!gq.empty() && !rq.empty()){
        int gss= gq.size(), int rss = rq.size();
    }
}
int main(){ 
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> g >> r;
    for(int i =0; i < n; i++){
        for(int j=0; j < m ; j++){
            cin >> f[i][j];
            if(f[i][j] == 2){
                gsz++;
                gvt.push_back({i,j});
            }
        }
    }
    for(int i =1; i <= gsz; i++){
        gperv.push_back(i);
    }
    do{
        vector<pi>gst;
        vector<pi>rst;
        for(int i: gperv){
            if(i >g + r)continue;
            if(i <= g) gst.push_back(gvt[i-1]);
            else rst.push_back(gvt[i-1]);
        }
        bfs(gst,rst);
    }while(next_permutation(gperv.begin(),gperv.end()));
}