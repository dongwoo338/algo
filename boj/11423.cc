#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
bitset<10000001> v;
int suc[10000001];
int a, b;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 3; i*i<=10000000; i+=2){
        if(v[i])continue;
        for(int j=i+i; j<=10000000; j+=i)v[j]=1;
    }
    suc[2]=1;
    for(int i=2;i<=10000000; i++){
        suc[i] +=suc[i-1];
        if((i&1)&&!v[i])suc[i]++;
    }
    while(cin >> a >> b){
        if(a>b)swap(a,b);
        cout << suc[b]-suc[a-1] << "\n";
        cout << "\n";
    }
}