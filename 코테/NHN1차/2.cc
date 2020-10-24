#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int>a(m);
    int ans=0;
    while(n--){
        for(int i =0; i < m; i++){
            int k;
            cin >> k;
            a[i]+=k;
        }
        for(int i =0; i <m; i++)cout << a[i]<<" ";
        cout << "\n";
        int l,r = (int)2e9;
        int s=0;
        while(s<m - 1 &&a[s]<=a[s+1])s++;
        l = a[s];
        stack<int>st;
        for(int i =s; i < m; i++){
            if(i==m-1){
                if(a[i] > a[i - 1]){
                    r = a[i];
                    while(!st.empty()){
                        ans += (min(l,r)-a[st.top()]);
                        a[st.top()]=min(l,r);
                        st.pop();

                    }                   
                }
                else{
                    ans += (a[i-1]-a[i]);
                    a[i]=a[i-1];
                }
            }
            else{
                if(a[i]>a[i+1]){    
                    r = a[i];
                    while(!st.empty()){
                        ans += (min(l,r)-a[st.top()]);
                        
                        a[st.top()]=min(l,r);
                        st.pop();
                    }
                    l = r;
                }
                else st.push(i);
            }
        }
        for(int i =0; i <m; i++)cout << a[i]<<" ";
        cout << "\n";
        cout << ans << "\n";
    }
    cout << ans;
}