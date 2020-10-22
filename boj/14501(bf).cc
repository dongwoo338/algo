#include<bits/stdc++.h>
using namespace std;
int day[16];
int cost[16];
int maxcost;
int n;
void dfs(int i,int nowcost){
    if(i>n)return;
    maxcost = max(maxcost,nowcost);
    //이 강의를 들을경우
    dfs(i+day[i], nowcost+cost[i]);
    //이 강의를 듣지않은경우
    dfs(i+1, nowcost);
}
int main(){
    cin >> n;
    for(int i=0; i < n; i++)cin >> day[i] >> cost[i];
    dfs(0,0);
    cout << maxcost;
}