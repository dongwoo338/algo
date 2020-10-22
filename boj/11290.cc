#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int suc[10001];
int w[10001];
bool isprime[10001];
vector<int> prime;
int n;
int ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i =2; i <= 100; i++){
        if(!isprime[i]){
            for(int j= i+i; j<= i*i; j+=i){
                isprime[j] = 1;
            }
        }
    }
    for(int i =2; i<=10000; i++)if(!isprime[i])prime.push_back(i);
    for(int i : prime){
        int x=10101, y = 5;
        while(y<=10000){
            if(x%i==0){
                w[i]=y;
                break; 
            }
            x%=i, x*=100, x+=1;
            y+=2;
        }
    }
    for(int i=5; i<=n; i++){
        if(w[i]==i-2)ans++;
    }
    cout << ans;
}