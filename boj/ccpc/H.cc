#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
const int N = 100005;
int n,a[N];
int po[N],pe[N];//ps i ~ n odd even
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = n; i >= 1; i--){
        if(i&1){
            po[i] = po[i+2];
            po[i]+=a[i];
        }
        else{
            pe[i] = pe[i+2];
            pe[i]+=a[i];
        }
    }   
    int ans=po[1];
    for(int i = 1; i <= n; i+=2){
        int val = po[1];
        val -= po[i];
        val += pe[i+1];
        ans=max(ans,val);
    }
    cout<<ans;
}