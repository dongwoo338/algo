#include<bits/stdc++.h>
using namespace std;
int ss,ee;
int d[500005][2];//
typedef pair<int,int> pi;
int main(){
    cin >> ss >> ee;
    memset(d,-1,sizeof(d));
    d[ss][0]=0;
    queue<pi>q;
    q.push({ss,0});
    while(q.size()){
        auto [x,hs]=q.front(); q.pop();
        for(int i =0; i < 3; i++){
            int dx;
            if(i==0)dx=x+1;
            else if(i==1)dx=x-1;
            else dx=x*2;
            if(dx<0||dx>500000)continue;
            if(d[dx][(hs^1)&1]==-1){
                d[dx][hs^1]=d[x][hs]+1;
                q.push({dx,hs^1});
            }
        }
    }
    int ans =(int)1e9;
    for(int i =0; i+ee<=500000; i++){
        ee+=i;
        if(d[ee][i&1]!=-1&&d[ee][i&1]<=i){
            ans=i;
            break;
        }
    }
    if(ans==(int)1e9)cout << -1;
    else cout << ans;
}