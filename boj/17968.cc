#include<bits/stdc++.h>
using namespace std;
int a[1004];
int main(){
    a[0]=a[1]=1;
    int n;
    cin >> n;
    for(int i =2; i <= n; i++){
        for(int j = 1; ;j++){
            bool isp = 1;
            for(int k = 1; i-2*k>=0; k++){
                if(j-a[i-k]==a[i-k]-a[i-2*k]){
                    isp=0;
                    break;
                }
            }
            if(isp){
                a[i]=j;
                break;
            }
        }
    }
    cout << a[n];
}