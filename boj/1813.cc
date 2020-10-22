#include <iostream>
using namespace std;
int n;
int a[100001];
int main(){
    cin >> n;
    for(int i =0; i < n; i++){
        int k;
        cin >> k;
        a[k]++;
    }
    for(int i = 100000; i >= 0; i--){
        if(a[i]==i){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}