#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 100001
using namespace std;
typedef long long ll;
int n, m, x, y, d[MAX_N + 1];
int f[MAX_N+1];
int clk;
int euv[2*MAX_N+2];
int seg[4*MAX_N+4];
vector<vector<int>> adj;
void init() {
    for (int i = clk - 1; i >= 1; i--){
		if(d[seg[i<<1]]<d[seg[i<<1|1]])seg[i]=seg[i << 1];
		else seg[i]= seg[i<<1|1];
	}
}
int minquery(int lo, int hi, int node, int x, int y) {
	if(hi > lo)swap(lo,hi);
    if (y < lo || hi < x)
        return -1;
    if (lo <= x&&y <= hi)
        return seg[node];
    int mid = (x + y) >> 1;
	int lq = minquery(lo, hi, node * 2, x, mid);
	int rq = minquery(lo, hi, node * 2 + 1, mid + 1, y);
	if(lq==-1)return seg[rq];
	if(rq==-1)return seg[lq];
	if(d[lq]<d[rq])return seg[lq];
	else return seg[rq];
}
void dfs(int u,int pu){
	d[u] = d[pu] + 1;
	f[u] = clk; // 노드 u가 euv list에서 어떤 인덱스이 있는지 저장
	euv[clk++] = u;
	for(int v : adj[u]){
		if(v==pu)continue;
		dfs(v,u);
		euv[clk++]=u;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	adj.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
    d[0]= -1;
	dfs(1, 0);
	for(int i = 0; i < clk; i++)seg[i+clk] = euv[i];
    init();
	cin >> m;
	while (m--) {
		cin >> x >> y;
		cout << minquery(f[x],f[y],1,0,clk-1)<<"\n";
	}
	return 0;
}