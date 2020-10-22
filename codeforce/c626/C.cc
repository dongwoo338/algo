#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const  ll MAX= 1e16;
int t;
ll n ,k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        ll a[31];
        cin >> n >> k;
        ll pk =k;
        for(int i =0; i < n; i++)cin >> a[i];
        while(1){
            if(pk*k>MAX)break;
            pk*=k;
        }
        bool ispos= 1;
        while(pk){
            int bcnt=0;
            for(int i =0; i < n; i++){
                if(a[i] >= pk){
                    a[i]-=pk;
                    bcnt++;
                }
            }
            if(bcnt>=2){
                ispos=0;
                break;
            }
            pk/=k;
        }
        for(int i=0; i < n; i++)if(a[i])ispos=0;
        if(ispos)cout<<"YES"<<"\n";
        else cout << "NO"<<"\n";
    }
}