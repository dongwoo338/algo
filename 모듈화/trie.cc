int trie[200001 * 31][2];//다음 elemnet가 어디인가
int cnt[200001 * 31];//이 노드에 해당하는 원소가 몇개 있는가
void update(int x,int c) {
    bitset<31>v;
    for (int i = 30; i >= 0; i--)v[i] = (x & (1 << i));
    int now = 0;//현재 위치를 가르키는 인덱스
    for (int i = 30; i >= 0; i--) {
        if (trie[now][v[i]]) now = trie[now][v[i]];
        else {
            now =trie[now][v[i]] = ++clk;
        }
        cnt[now] += c;
    }
}
int query(int x) {
    bitset<31>v;
    for (int i = 30; i >= 0; i--)v[i] = (x & (1 << i));
    int ret = 0;
    int now = 0;
    for (int i = 30; i >= 0; i--) {
        if (cnt[trie[now][!v[i]]]) {
            now = trie[now][!v[i]];
            ret += (1 << i);
        }
        else now = trie[now][v[i]];
    }
    return ret;
}