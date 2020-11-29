#include<bits/stdc++.h>
using namespace std;
int pa[1001][3];//  e i o 
int n,t;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        cin >> s;
        vector<int>av,uv;
        memset(pa,0,sizeof(pa));
        int s= 1;
        int e= 2*n;
        for(int i = 1; i <= n; i++){
            for(int j =0; j < 3; j++)pa[i][j]=pa[i-1][j];
            if(s[i]=='a')av.push_back(i);
            else if(s[i]=='u')uv.push_back(i);
            else if(s[i]=='e')pa[i][0]++;
            else if(s[i]=='i')pa[i][1]++;
            else if(s[i]=='o')pa[i][2]++;
        }
        int apos = 0, upos=0;
        if(av.empty()||uv.empty()){
            cout << "-1 -1\n";
            continue;
        }
        while(1){
            bool ispos=1;
            int ss = av[apos], ee = uv[upos];
            for(int j= 0; j < 3; j++){
                if(pa[ee][j]-pa[ss-1][j]==0)ispos=0;
            }
            if(ispos){
                if(ee-ss<e-s){

                }
            }
            if(apos>=av.size()||upos>=uv.size())break;         
        }
    }
}  