vector<int> makeprime(const int N) {// N보다 작은 소수의 벡터를 리턴
    vector<bool>isp(N + 1, 0);
    vector<int> v;
    for (int i = 2; i * i <= N; i++) {
        if (!isp[i]) {
            for (int j = i * i; j <= N; j += i) {
                isp[j] = 1;
            }
        }
    }
    for (int i = 2; i <= N; i++)if (!isp[i])v.push_back(i);
    return v;
}