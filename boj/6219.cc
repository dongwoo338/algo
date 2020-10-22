#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
const int N = 4000001;
bitset<N> v;
int a, b, x, ans;
bool val(int n){
    while(n){
        if(n%10==x)return 1;
        n/=10;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> a >>b >> x;
    vector<int> primes;
    primes.push_back(2);
    for(int i= 3; i*i < N; i+=2){
        if(v[i])continue;
        for(int j = i*i; j< N; j+=i){
            v[j]= 1;
        }
    }
    for(int i= 3; i < N; i+=2){
        if(!v[i])primes.push_back(i);
    }
    for(int i : primes){
        if(i>b)break;
        if(i<a)continue;
        ans += val(i);
    }
    cout << ans;
}