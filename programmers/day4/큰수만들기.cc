#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
queue<int>a[11];
string solution(string number, int k) {
    string answer = "";
    k = number.length() -k;
    for(int i =0; i  < number.length(); i++){
        a[number[i]].push(i+1);
    }
    int loc=-1;
    while(k--){
        for(int j =9; j>=0;j--){
            while(a[j].size()&&a[j].front()<loc)a[j].pop();
            if(a[j].size()&&number.length()-a[j].front()<=k){
                answer+=j;
                loc = a[j].front();
                a[j].pop();
                break;
            }
        }
    }
    return answer;
}
int main(){
    cout << solution("1924",0);
}

