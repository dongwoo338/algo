const int SZ = 1 << 20;
int seg[2 * SZ];
int n, k;
void update(int p, int val) {
    seg[p += SZ] += val;
    p >>= 1;
    while (p) {
        seg[p] = seg[p << 1] + seg[p << 1 | 1];
        p >>= 1;
    }
}
int kth(int s, int e, int ind, int k) {
    if (s == e)return s;
    int mid = (s + e) / 2;
    if (k <= seg[ind * 2])return kth(s, mid, ind * 2, k);
    else return kth(mid + 1, e, ind * 2 + 1, k - seg[ind * 2]);
}