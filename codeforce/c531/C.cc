#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n ,x,y,ans;
int t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x >> y;
    priority_queue<int>pq;
    for(int i=0; i < n; i++){
        int tm;
        cin >> tm;
        pq.push(-tm);
    }
    if(x>y)cout << n;
    else{
        while(!pq.empty()){
            int tp = -pq.top();
            pq.pop();
            if(t%2==0){
                if(tp-x>0)break;
            }
            else{
                pq.push(tp+y);
            }
            t++;
        }
        cout << ans;
    }
}