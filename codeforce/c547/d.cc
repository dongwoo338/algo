#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
string s1, s2;
int a[150001];
int b[150001];
int n;
queue<int>adj[26];
vector<pair<int,int>> ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s1 >> s2;
    for(int i =0; i < s1.length(); i++){
        if(s1[i] == '?') a[i]=2;
        else adj[s1[i]-'a'].push(i);
    }
    for(int i =0; i < s1.length(); i++){
        if(s2[i] == '?') b[i]=2;
        else{
            char c= s2[i]-'a';
            if(!adj[c].empty()){
                int am = adj[c].front(); adj[c].pop();
                a[am]=1; b[i]=1;
                ans.push_back({am,i});
            }
        }
    }
    queue<int> aq; queue<int> anot;
    queue<int> bq; queue<int> bnot;
    for(int i =0; i < n; i++){
        if(a[i]==2)aq.push(i);
        if(a[i]==0)anot.push(i);
        if(b[i]==2)bq.push(i);
        if(b[i]==0)bnot.push(i);
    }
    while(aq.size&&bnot.size()){
        ans.push_back({aq.front(),bnot.front()});
        aq.pop(); bnot.pop();
    }
    while(anot.size()&&bq.size()){
        ans.push_back({anot.front(),bnot.front()});
        anot.pop();bq.pop();
    }
    while(aq.size()&&bq.size()){
        ans.push_back({aq.front(),bq.front()});
        aq.pop();bq.pop();
    }
    cout << ans.size() << "\n";
    for(auto i :ans){
        cout << i.first+1 << " "<<i.second+1 << "\n";
    }
}