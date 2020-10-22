#include<bits/stdc++.h>
using namespace std;
bool bisearch(vector<int> &v, int k){
    int lo =0; int hi= v.size()-1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(v[mid]==k)return 1;
        if(v[mid]<k)lo=mid;
        else hi =mid - 1;
    }   
    return 0;
}
int main(){
    vector<int> v= {2,3,5,6};
    int k;
    cin >> k;
    cout<<bisearch(v,k);
}