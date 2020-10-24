#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
bool isfast[26];
int cnt[26];
int a[26];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n>>m;
    for(int i =0; i  <m ;i++){
        char c;
        cin >> c;
        isfast[c-'A']=1;
    }
    int q;
    cin >> q;
    for(int i =0; i < n -1;i++)a[i]= i + 1;
    int loc=0, sul=0; cnt[0]++;
    int dir=0;
    for(int i =0; i < q; i++){
        int x;
        cin >> x;
        if(x<0){
            x *= -1;
            dir =1;
        }
        while(x--){
            if(dir==0){
                if(loc==n-2)loc=0;
                else loc++;
            }
            else{
                if(loc==0)loc=n-2;
                else loc--;
            }
        }
        if(isfast[a[loc]]){// 술래 그대로, 횟수 추가
            cnt[sul]++;
        }
        else{
            swap(sul,a[loc]);
            cnt[sul]++;
        }
    }
    for(int i =0; i < n -1; i++){
        char cc = 'A'+a[i];
        cout <<cc<<" "<<cnt[a[i]]<<"\n";
    }
    char cc= 'A'+sul;
    cout << cc <<" "<<cnt[sul]<<"\n";
}