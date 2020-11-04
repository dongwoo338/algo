#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    int cnt= 0 ;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int &i:v)cin>>i;
        queue<int>q;
        q.push(1);
        set<int>s;
        for(int i = 2; i<=n ;i++)s.insert(i);
        int nl= 2;//다음에 볼거
        
    }
}