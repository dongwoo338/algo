#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[300002];
    for(int i=0; i < n; i++)cin>>a[i];
    int here= n;
    for(int i= n - 1; i >=0; i--){
        if(a[i]==here)here--;
    }
    cout << here;
}