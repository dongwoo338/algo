#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int n;
int a[200001];
int scnt;
vector<int>diff;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i =0; i < n-1; i++)cin >> a[i];
    bool isok=1;
    diff.push_back(1);
    int now = 1;
    for(int i =0; i < n -1; i++){
        now+=a[i];
        diff.push_back(now);
    }
    sort(diff.begin(),diff.end());
    for(int i = 1; i < n; i++){
        if(diff[i]-diff[i-1]!=1){
            isok=0;break;
        }
    }
    if(!isok)cout<<-1;
    else{
        int now = 1 + ( 1-diff[0]);
        cout << now << " ";
        for(int i =0; i < n - 1; i++){
            now += a[i];
            cout << now << " ";
        }
    }
}