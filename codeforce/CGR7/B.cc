#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a[200001];
    int n;
    cin >> n;
    cin >> a[0];
    int maxt = a[0];
    for(int i =1; i < n; i++){
        int k;
        cin >> k;
        if(k<0){
            a[i] = k + maxt;
        }
        else{
            maxt +=k;
            a[i] = maxt;
        }
    }
    for(int i =0; i <n; i++)cout << a[i] << " ";
}