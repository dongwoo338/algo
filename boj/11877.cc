#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 1e15+1;
typedef pair<int,int> pi;
ll n, x;
ll a[1000001];
int clk=0;
vector<int> vt;
vector<int>mvt;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    if(n<=2)cout << -1;
    else{
        // sum[1, n-2]
        for(int i = 1; i<=n-2; i++){
            if(x>=n-1-i){
                x -=(n-i-1);
                vt.push_back(i);
            }
            else mvt.push_back(i);
        }
        if(x>0)cout << -1;
        else{
            sort(vt.begin(),vt.end());
            sort(mvt.begin(),mvt.end(),greater<>());
            cout << n<<" ";
            for(int i: vt)cout << i<<" ";
            cout << n-1 << " ";
            for(int i: mvt)cout<< i << " ";
        }
    }
}