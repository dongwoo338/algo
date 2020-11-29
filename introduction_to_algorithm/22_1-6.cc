/*introduction to algorithm (22_1-6.cc)
    노드가 n개인 그래프가 인접행렬 형태로 주어졌을때
    O(n)시간안에 universal sink 존재여부 알아보기
*/
#include<iostream>
int n, m;
using namespace std;
const int N =1001;
bool a[N][N];

// sink node가 존재하면 그 노드의 번호를 return
// 없을시 -1 return
int sinkExist(){
    int i =1, j =1;
    // i번노드가 sink인지 아닌지 확인해야한다.
    while(i<=n&&j<=n){
        if(a[i][j])i++;
        else j++;
    }
    if(i>n)return -1;

    // i번 노드가 sink인지 다시한번 확인해야 한다.
    for(int j= 1; j <= n; j++){
        if(i==j)continue;
        if(a[i][j])return -1;
        if(!a[j][i])return -1;
    }
    return i;
}
int main(){
    cin >> n >> m;
    for(int i =0; i < m; i++){
        int u,v; // edge u - > v
        cin >> u >> v;
        a[u][v]=1;   
    } 
    cout << sinkExist();
}