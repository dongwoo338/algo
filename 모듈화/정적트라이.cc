#include<bits/stdc++.h>
using namespace std;
const int MN= 1001*4001,MC=26;//최대 문자수, 문자열개수

struct Trie{
    int clk=0;
    int trie[MN][MC];
    bool term[MN];
    void init(){
        memset(trie,0,sizeof(trie));
        memset(term,0,sizeof(term));
        clk= 0;
    }
    void insert(string &s){
        int now=0;
        for(char &i: s){
            if(!trie[now][i-'a'])trie[now][i-'a']=++clk;
            now = trie[now][i-'a'];
        }
        term[now]=1;
    }
    bool find(string &s){
        int now =0;
        for(char &i : s){
            if(!trie[now][i-'a'])return 0;
            now =trie[now][i-'a'];
        }
        if(term[now])return 1;
        return 0;
    }
}t1;