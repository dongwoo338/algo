#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ,k;
    cin >> n >> k;
    if(n&1){
        if(k==1){
            cout<<1;
            for(int i =0; i < n -1; i++)cout<<0;
        }
        else{
            for(int i=0; i < k - 1;i++)cout<<1;
            cout<<0;
            for(int i =0; i < n -k; i++){
                if(i&1)cout<<0;
                else cout<<1;
            }
        }
    }
    else{
        if(k==2){
            cout<<11;
            for(int i=0; i < n -k; i++)cout<<0;
        }
        else{
        for(int i =0; i < k -1; i++)cout<<1;
        cout << 0;
        for(int i =0 ; i < n  -k; i++){
            if(i&1)cout<<0;
            else cout << 1;
        }
        }
    }
}