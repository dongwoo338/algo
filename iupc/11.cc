#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int n, m;
int c[3];
const int N = 51; // 인경호의 최대 크기
const int MAX = (int)2e9; // 최대값 초기화
int d[N][N][16]; 
int state[N][N];
int ans = MAX;
// 룩의 이동
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
// 비숍의 이동
int dir2[4][2] = {{-1,-1},{-1,1},{1,1},{1,-1}};
// 나이트의 이동
int dir3[8][2] = { {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1} };
// x,y좌표, 현재상태 정보를 가진다.
struct Q {
    int x, y, st;
    Q(int x, int y, int st) :
        x(x), y(y), st(st) {}
};
bool operator<(Q q1, Q q2) {
    return q1.x < q2.x;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    // A,B,C (나이트, 비숍, 룩)이 이동하는 방향으로 이동할떄의 비용
    for (int i = 0; i < 3; i++)cin >> c[i];
    // 오리의 시작 위치
    int st, en;
    cin >> st >> en;

    // 먹이의 개수
    cin >> m;
    for (int i = 0; i < m; i++) {
        // 먹이의 위치
        int x, y;
        cin >> x >> y;
        state[x][y] = (1<<i);
    }

    priority_queue<pair<int, Q>>pq;// dist, Q
    fill(&d[0][0][0], &d[N - 1][N - 1][15], MAX);
    d[st][en][0] = 0;
    pq.push({ 0,Q(st,en,0) });
    while (pq.size()) {
        int hd= -pq.top().first;
        auto [hx,hy,hs] = pq.top().second;
        pq.pop();
        if( hd > d[hx][hy][hs])continue;
        if( hd == (1 << m)){
            ans = min(ans, hd);
            break;              
        }
        //룩이 이동하는 방향(직선)으로 이동할 때
        for(int i =0; i <4; i++){
            int nx= hx, ny= hy;
            while(1){
                nx += dir[i][0]; ny +=dir[i][1];
                if(nx<0||nx>=n||ny<0||ny>=n)break;
                int ns = hs|state[nx][ny];
                if(hd+c[2]<d[nx][ny][ns]){
                    d[nx][ny][ns]=hd+c[2];
                    pq.push({-hd-c[2],Q(nx,ny,ns)});
                }
            }
        }

        // 비숍이 이동하는 방향(대각선)으로 이동할때
        for(int i =0; i <4; i++){
            int nx= hx, ny= hy;
            while(1){
                nx += dir2[i][0]; ny +=dir2[i][1];
                if(nx<0||nx>=n||ny<0||ny>=n)break;
                int ns = hs|state[nx][ny];
                if(hd+c[1]<d[nx][ny][ns]){
                    d[nx][ny][ns]=hd+c[1];
                    pq.push({-hd-c[1],Q(nx,ny,ns)});
                }
            }
        }
        // 나이트가 이동하는 방향으로 이동할 때
        for(int i =0; i < 8; i++){
            int nx = hx + dir3[i][0], ny = hy + dir3[i][1];
            if(nx<0||nx>=n||ny<0||ny>=n)break;
            int ns= hs|state[nx][ny];
            if(hd+c[0]<d[nx][ny][ns]){
                d[nx][ny][ns] = hd+ c[0];
                pq.push({-hd-c[0], Q(nx,ny,ns)});
            }
        }
    }
    cout << ans;
}