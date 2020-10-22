#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m=0;
    int n;
    cin >> n;
    for(int i = 17; i>=0; i--) m+=(1<<i);
    cout << 3 << " "<<3 << " "<<"\n";
    for(int i =0; i < 3; i++){
        for(int j =0; j < 3; j++){
            if(i==2 && j== 1)cout << m - n<< " ";
            else cout << m << " ";
        }
        cout << "\n";
    }
}