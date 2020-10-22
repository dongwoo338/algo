#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    priority_queue<pi> pq;
    int n;
    cin >> n;
    for(int i=1; i <= n; i++){
        int val;
        cin >> val;
        pq.push({val,i});
    }
    bool isfir=1;
    int l,r;
    bool isok=1;
    while(!pq.empty()){
        if(isfir){
            l=r=pq.top().second;
            pq.pop();
            isfir=0;
        }
        else{
            int loc =pq.top().second;
            pq.pop();
            if(loc == l -1)l=loc;
            else if(loc == r+1)r=loc;
            else {
                isok =0;
                break;
            }
        }
    }
    if(isok)cout <<"yes";
    else cout << "no";
}