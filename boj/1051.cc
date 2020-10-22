#include <iostream>
#include <string>
#include <set>
#include <algorithm>// 알고리즘 헤더 이문제에선 min()에서 사용
using namespace std;
int ans;
int arr[53][53];// n과 m은 50보다작은 자연수 -> 50보다 크게 이중배열을 잡아줘야한다.(지금처럼 넉넉하게 잡아줘도됨)
int n ,m;
// 가장왼쪽 위의 꼭지점과 나머지 꼭지점의 숫자가 모두 같은지 확인!!
// 같으면1 그외의 경우(같지않거나, 그크기의 사각형이 나오지않거나..) 0
bool check(int i,int j,int k){
    // 주어진 사각형이 범위를 벗어나는경우
    if(i+k>=n ||j+k>=m)return 0;
    // 네꼭지점의 수가 모두 같은지 확인
    if(arr[i][j]==arr[i][j+k-1]&&arr[i][j+k-1]==arr[i+k-1][j] && arr[i+k-1][j]==arr[i+k-1][j+k-1])return 1;
    return 0;
    // 네꼭지점의수가 같은지확인하는 좀더 간단한방법
    // 네 꼭지점의 수를 전부 set<int> s선언해서 넣은다음에
    // if(s.size()==1) return 1;자료구조 set은 중복원소를 제거해주기때문에
    // set의 원소가 1개이면 -> 모든 원소는 같다
}
int main(){
    cin >> n >> m;// 각 행과 열
    for(int i=0; i < n; i++){//문제에서 입력형식이 각칸에 들어갈 숫자로 주어지지않음 -> 문자열로 받으면 편리
        string s;
        cin >> s;
        for(int j =0; j < m; j++){
            arr[i][j] = s[j] -'0';//string에 들어있는것은 문자열이기 때문에 '0'문자열을 빼주어야 배열에 들어갈 숫자를 얻을 수 있다.
        }
    }
    int maxize = min(n,m);//최대로 커질수있는 정사각형의 한 변의 길이
    // 3중포문
    // i j -> 모든 인덱스에 대해서
    // k ->최대로 커질수있는 정사각형의크기까지 모든 경우를 검사
    for(int i=0;i <n; i++){
        for(int j =0; j < m; j++){
            for(int k=1; k <= maxize; k++){
                // 같은걸 확인했으면 정답을 갱신
                if(check(i,j,k))ans=max(ans,(k*k));
            }
        }
    }
    cout << ans;
}