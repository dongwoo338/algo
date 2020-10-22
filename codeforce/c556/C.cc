#include<bits/stdc++.h>
using namespace std;

int ocnt,ecnt;
int main(){
    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        int k;
        cin >> k;
        if(k==1)ocnt++;
        else ecnt++;
    }
    if(ecnt&&ocnt){
        cout << 2 <<" "<<1<<" ";
        for(int i =0; i < ecnt - 1;i++)cout<<2<<" ";
        for(int i= 0; i < ocnt - 1;i++)cout<<1<<" ";
    }
    else{
        
        for(int i =0; i < ecnt;i++)cout<<2<<" ";
        for(int i= 0; i < ocnt;i++)cout<<1<<" ";       
    }
}