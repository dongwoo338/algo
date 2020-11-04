#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int a[51];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <=n; i++)cin >> a[i];
    int s;
    cin >> s;
    for(int i = 1; i< n; i++){
        int maxt = a[i];
        int pos = -1;
        for(int j = i + 1; j <= n&&j-i<=s; j++){
            if(a[j]>maxt){
                maxt = a[j];
                pos = j;
            }
        }
        if(pos!=-1){
            s-=(pos-i);
            while(pos!=i){
                swap(a[pos],a[pos-1]);
                pos--;
            }
        }
    }
    for(int i = 1; i<= n; i++)cout << a[i]<<" ";
}