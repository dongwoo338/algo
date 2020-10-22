#include<iostream>
using namespace std;
bool f(int a,int b,int c){
    if((a+b)==c){
        cout<<a<<"+"<<b<<"="<<c;
        return 0;
    }
    
    if((a*b)==c){
        cout<<a<<"*"<<b<<"="<<c;
        return 0;
    }
    
    if((a-b)==c){
        cout<<a<<"-"<<b<<"="<<c;
        return 0;
    }
    
    if((a/b)==c){
        cout<<a<<"/"<<b<<"="<<c;
        return 0;
    }
    return 1;
}
int main(){
    int a,b,c;    
    cin >> a >> b >> c;
    if(f(a,b,c))f(b,c,a);
}