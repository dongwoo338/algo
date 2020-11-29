#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int>>G, TG;
bool pos[1001];
bool vis[1001];
int scsiz[1001];// scc size
int sccp[1001]; // one dag [scc~ scc+sccp]
int pcnt[1001];// scc가 아닌 노드의 
int sccnt=0;
stack<int> tp;// dfs위상정렬
vector<int>samc;
void dfs(int u) {
	vis[u] = 1;
	for (int v : G[u]) {
		if (!vis[v])dfs(v);
	}
	tp.push(u);
}
int dfs2(int u) {
	int ret = 1;
	vis[u] = 0;
	samc.push_back(u);
	for (int v : TG[u]) {
		if (vis[v])ret += dfs2(v);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	G.resize(n + 1);
	TG.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int xi;
		cin >> xi;
		G[i].push_back(xi);
		TG[xi].push_back(i);
	}
	// outdegree가 0인노드먼저 dfs
	for(int i = 1; i <=n ;i++){
		if(TG[i].empty())dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i])dfs(i);
	}
	while (!tp.empty()) {
		int u = tp.top();
		samc.clear();
		if (vis[u]){
			int sz =dfs2(u);	
			if(sz==1&&G[u][0]!=u){
				pcnt[G[u][0]]+=(pcnt[u]+1);				
			}
			else{
				for(int i : samc){
					sccp[sccnt]+=pcnt[i];
				}
				scsiz[sccnt++]=sz;
			}
		}
		tp.pop();
	}
	pos[0]=1;
	for(int i =0; i < sccnt; i++){ // 한 scc 성분이 가질 수 있는 종류의 범위 [scsiz, scsiz+sccp]
	// using knapsack
		for(int  j =n; j >= 0; j--){
			if(pos[j]){
				for(int tp = scsiz[i]; tp <= scsiz[i]+sccp[i] && j+tp<=n; tp++){
					pos[j+tp]=1;
				}
			}
		}
	}
	for(int i = k ; i >=0; i--){
		if(pos[i]){
			cout <<i << "\n";
			break;
		}
	}
}