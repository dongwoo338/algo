#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int n , m, topl;
priority_queue<int> pq;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n>> m;
    vector<int>v(n);
    for(int&i:v)cin>>i;
    for(int i =0; i < n - 1; i++){
        pq.push(v[i]);
        while(1){
            if(pq.top()+topl>=m)pq.pop();
            else break; 
        }
        if(v[i]>v[i+1]){
            int tm = 1e9;
            if(pq.size())tm = pq.top()-v[i+1];
            tm = min(tm, m- pq.top());
            topl =max(topl,tm);
        }
        cout << topl << "\n";
    }
    cout << topl;
}