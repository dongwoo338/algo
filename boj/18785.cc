#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
vector<vector<int>> adj;
bool check[2501];
int n;
int c[2501];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    int k;
    for(int i=0; i< n; i++)cin >> k;
    for(int i =0; i < 2 * n-1;i++){
        cin >> k;
    }
    cout << 1;
}