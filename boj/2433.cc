#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n, m, k;
const int N =(int)1e6+1;
int ming[2*N], maxg[2*N], a[N];
int maxq(int s,int e){
    int ret = (int)-1e9;
    e++;
    for(s +=n, e +=n; s < e ; s>>=1, e>>=1){
        if(s&1)ret= max(ret, maxg[s++]);
        if(e&1)ret= max(ret, maxg[--e]);
    }
    return ret;
}
int minq(int s,int e){
    int ret = (int)1e9;
    e++;
    for(s +=n, e +=n; s < e ; s>>=1, e>>=1){
        if(s&1)ret= min(ret, ming[s++]);
        if(e&1)ret= min(ret, ming[--e]);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i =0; i < n; i++){
        cin >> a[i];
        ming[n+i]=maxg[n+i]=a[i];
    }
    for(int i = n - 1; i >= 1; i--){
        ming[i]=min(ming[i*2],ming[i*2+1]);
        maxg[i]=max(maxg[i*2],maxg[i*2+1]);
    }
    //for(int i = 1; i <= 14; i++)cout << ming[i]<<" ";

    vector<int>ans;
    for(int i =0; i < n- m + 1; i++){
        int dif = maxq(i,i+m-1)-minq(i,i+m-1);
        if(dif<=k)ans.push_back(i+1);
    }
    if(ans.empty())cout<<"NONE";
    else {
        for(int i :ans)cout << i<<"\n";
    }
}