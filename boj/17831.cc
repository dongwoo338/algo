// 주석무시(수정해야함)
#include <bits/stdc++.h>
using namespace std;
const int MAX =100001;
int a[MAX], b[MAX], n;
string sa,sb;
int ans = 2*MAX;
int main(){
    cin >> n;
    cin >> sa >> sb;
    for(int i =0; i < n; i++)a[i] = sa[i]-'0';
    for(int i =0; i < n; i++)b[i] = sb[i]-'0';
    //첫번째 string과 두번째 string배열을 xor한값을 a,b두배열에 다시집어넣는다(처음에 스위치를 눌럿을 경우와 안눌럿을 2가지 경우를 따져줘야 되기떄문에)
    for(int i =0; i < n; i++)b[i]=a[i]^=b[i];
    //전부같게(전부0으로)만드는것이목적이므로(같으면 0, 다르면 1로)
    int po = 1, cnt = 0;// po는 현재 스위치의 위치,cnt는 스위치를 누른횟수
    //case1 첫번쨰 스위치를 누르지않았을경우
    while(1){
        // 현재 스위치가 보는 전위치 전구가 1이거나 스위치전구가1이면 스위치를 눌러야한다
        cout << po << " " << cnt<<"\n";
        if(a[po+1]&&a[po]){
            po++; continue;
        } 
        if(a[po-1]||a[po]){
            a[po-1]^=1;a[po]^=1;a[po+1]^=1;
            cnt++;
        }
        //마지막스위치에 가면 탈출
        if(po==n-1){
            if(!(a[n-2]|a[n-1]))ans=cnt;
            break;
        }
        po++;
    }
    //case2 첫번째 스위치를 눌렀을 경우
    po =1, cnt = 1; b[0]^=1;b[1]^=1;
    while(1){
        //마지막스위치에 가면 탈출
        
        if(a[po-1]&&a[po]){
            po++; continue;
        }         
        // 현재 스위치가 보는 전위치 전구가 1이거나 스위치전구가1이면 스위치를 눌러야한다
        if(b[po+1]||b[po]){
            b[po-1]^=1;b[po]^=1;b[po+1]^=1;
            cnt++;
        }
        if(po==n-1){
            if(!(b[n-1]|b[n-2]))ans=min(ans,cnt);
            break;
        }     
        po++;
    }
    if(ans==2*MAX) cout << -1;
    else cout << ans;
}