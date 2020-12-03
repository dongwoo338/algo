#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int d[2000006];
const int N= (int)1e6;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    memset(d,-1,sizeof(d));
    queue<int>q;
    for(int i =0; i <= (int)1e6; i++){
        d[N-i]=i;
        q.push(-i);
    }
    d[N]=1;
    while(q.size()){
        int h =q.front(); int  dd=d[h+N];
        q.pop();
        int nh = h + dd+N;
        if(d[nh]==-1&&nh>=0&&nh<=2*N){
            d[nh]=d[h+N]+1;
            q.push(nh);
        }
    }
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << d[n+N]<<"\n";
    }
}