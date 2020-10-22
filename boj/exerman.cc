#include<iostream>
#include<queue>
using namespace std;
int n ,k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    deque<pair<int,int>>dq;
    for(int i =0; i < n; i++){
        int v;
        cin >> v;
        while(!dq.empty()&&dq.back().first>v)dq.pop_back();
        dq.push_back({v,i});
        while(!dq.empty()&&dq.front().second<i-k+1)dq.pop_front();
        if(i>=k)cout << dq.front().first <<" ";
    }
}