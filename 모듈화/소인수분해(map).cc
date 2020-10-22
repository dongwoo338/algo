#include<bits/stdc++.h>
using namespace std;
// if want more fast.
// prime list and check only prime
map<int, int> sobun(int x) {
    map<int, int> mp;
    for (int i = 2; i * i <= x; i++) {
        if ((x % i) == 0) {
            while ((x % i) == 0) {
                mp[i]++;
                x /= i;
            }
        }
    }
    if (x >= 2)mp[x]++;
    return mp;
}
int main(){}
