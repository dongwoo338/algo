#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
bool a[101],b[101];
int cnt;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=0; i < n; i++)cin >> a[i];
    for(int i=0; i < n; i++)cin >> b[i];
    int i=0;
    while(i <= n-k){
        if(a[i]==b[i])i++;
        else{
            cnt++;
            for(int j =i; j <i+k; j++)a[j]^=1;
            int p=0;
            int j =i +1;
            while(j <i + k){
                if(a[j]!=b[j]){
                    if(p==0){
                        a[j]^=1;
                        p++;
                    }
                    else break;
                }
                j++;
            }
            if(p==0){
                i=i+k-1;
                a[i]^=1;
            }
            else i=j;
        }
    }
    bool isok=1;
    for(int i =0; i < n; i++)if(a[i]!=b[i])isok=0;
    if(!isok)cout<<-1;
    else cout << cnt;
}