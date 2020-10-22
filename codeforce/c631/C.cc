#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int n,m;
long long ps;
void err() {puts("-1");}
int len[100001];
int main(){
    cin >> n >> m;
    for(int i=1; i <=m; i++){
        cin >> len[i];
        ps += len[i];
        if(i+len[i]-1>n){
            err();
            return 0;
        }
    }
    if(ps<n){
        err();
        return 0;
    }
    for(int i =1; i<=m; i++){
        cout << max((long long)i,n-ps+1)<< " ";
        ps-= len[i];
    }
}