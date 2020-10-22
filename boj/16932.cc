#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int n, m, gnum;
int a[1001][1001];
int check[1001][1001];
int numofcon[1000001];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int ans;
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    int csize = 0;
    q.push({ x,y });
    check[x][y] = ++gnum;
    csize++;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (check[nx][ny] == 0 && a[nx][ny] == 1) {
                csize++;
                check[nx][ny] = check[x][y];
                q.push({ nx,ny });
            }
        }
    }
    numofcon[gnum] = csize;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] && check[i][j] == 0) {
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (1) {
                set<int> s;
                for (int k = 0; k < 4; k++) {
                    int x = i + dir[k][0], y = j+ dir[k][1];
                    if (x < 0 || x >= n || y < 0 || y >= m)continue;
                    s.insert(check[x][y]);
                }
                int tmp = 0;
                for (auto k : s){
                    tmp += numofcon[k];
                }
                a[i][j]?tmp--:tmp++;
                ans = max(ans, tmp);
           }
        }
    }
    cout << ans;
}