#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int a[501];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m,k;
    cin >> n >> m >> k;
    int nn = n ;//채워야 되는 N
    int num = n+1;// 이번 segment의 최소 원소
    if(n <=k*m&& (n >=k+m-1)){
        vector<int>seg;
        seg.push_back(m);
        for(int i =0; i < k - 1; i++)seg.push_back(1);
        nn -= (m+k-1);
        int pos= 1;
        while(nn--){
            seg[pos]++;
            if(pos == seg.size() -1)pos=1;
            else pos++;
        }
        pos = 1;
        for(int x : seg){
            num -=x;
            for(int j =0; j < x; j++){
                a[pos++] =num+j;
            }
        }
        for(int i = 1; i <= n; i++)cout << a[i]<<" ";
    }
    else{
        cout << -1;
    }
}