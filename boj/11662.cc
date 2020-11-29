#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double>pd;
pd d[4];
double dist(pd &a,pd &b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
int main(){
    for(int i =0; i < 4; i++)cin >> d[i].first>>d[i].second;
    int t =500;
    while(t--){
        //pA,qA,pB,qB
        pd pa,qa,pb,qb;
        pa={(2*d[0].first+d[1].first)/3,(2*d[0].second+d[1].second)/3};
        qa={(d[0].first+2 *d[1].first)/3,(d[0].second+2*d[1].second)/3};
        pb={(2*d[2].first+d[3].first)/3,(2*d[2].second+d[3].second)/3};
        qb={(d[2].first+2 *d[3].first)/3,(d[2].second+2*d[3].second)/3};
        if(dist(pa,pb)<=dist(qa,qb)){
            d[1] = qa, d[3] = qb;
        }
        else{
            d[0] = pa, d[2] = pb;
        }
        if(t==0){
            cout << fixed <<setprecision(6)<<dist(pa,pb)<<"\n";
        }
    }
}