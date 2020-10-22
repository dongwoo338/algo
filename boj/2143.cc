#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
ll k, ans;
int n , m;
map<ll,ll>mpa,mpb;//sums,cnt
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> k;
    cin >> n;   
    vector<ll> va(n+1);
    for(int i=1; i <=n; i++){
        cin >> va[i];
        va[i] += va[i - 1];
        for(int j = 0; j < i; j++){
            ll now=va[i]-va[j];
            if(mpa.count(now)==0)mpa.insert({now,1});
            else mpa[now]++;
        }
    }
    cin >> m;
    vector<ll> vb(m+1);
    for(int i=1; i <=m; i++){
        cin >> vb[i];
        vb[i] += vb[i - 1];
        for(int j = 0; j < i; j++){
            ll now=vb[i]-vb[j];
            if(mpb.count(now)==0)mpb.insert({now,1});
            else mpb[now]++;
        }
    }
    for(auto i : mpa){
        if(mpb.count(k-i.first))ans += i.second*mpb[k-i.first];
    }   
    cout <<ans;
}