#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char>st;
        for (char c : s) {
            if (c == ')') {
                stack<char>tm;
                string ww = "";
                while (st.top() != '(') {
                    ww+=(st.top());
                    st.pop();
                }
                reverse(ww.begin(), ww.end());
                st.pop();
                for(char ccc : ww)tm.push(ccc);
                if (st.top() >= 'A' && st.top() <= 'Z') {
                    char cc = st.top();
                    st.pop();
                    while (tm.size()) {
                        st.push(cc);
                        st.push(tm.top());
                        tm.pop();
                    }
                }
                else {
                    int cc = st.top() - '0';
                    st.pop();
                    string tms = "";
                    while (tm.size()) {
                        tms += tm.top();
                        tm.pop();
                    }
                    reverse(tms.begin(), tms.end());
                    while (cc--) {
                        for (char tc : tms) {
                            st.push(tc);
                        }
                    }
                }
            }
            else if ((c >= 'A' && c <= 'Z') && (st.size() && st.top() >= '1' && st.top() <= '9')){
                    int cnt = st.top() - '0';
                    st.pop();
                    while (cnt--)st.push(c);
            }
            else st.push(c);
        }
        string ans = "";
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}