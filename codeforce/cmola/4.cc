#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<int> oq, eq;
        ll asc=0, bsc=0;
        for(int i=0; i <n ; i++){
            int k;
            cin >> k;
            if(k&1)oq.push(k);
            else eq.push(k);
        }
        for(int i =0; i <n ; i++){
            if(i%2==0){// a
                if(eq.empty())oq.pop();
                else{
                    if(oq.size()&&(oq.top()>eq.top()))oq.pop();
                    else{
                        asc+=eq.top();
                        eq.pop();
                    }
                }
            }
            else{//b
                if(oq.empty())eq.pop();
                else{
                    if(eq.size()&&(eq.top()>oq.top()))eq.pop();
                    else{
                        bsc+=oq.top();
                        oq.pop();
                    }
                }            
            }
        }
            if(asc>bsc)cout<<"Alice\n";
            else if(asc==bsc)cout<<"Tie\n";
            else cout << "Bob\n";        
    }
}