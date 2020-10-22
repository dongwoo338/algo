#include<bits/stdc++.h>
#include<random>
using namespace std;
int main()
{
    mt19937 engine((unsigned int)time(NULL));                    // MT19937 난수 엔진
    uniform_int_distribution<int> distribution(0, 100);       // 생성 범위
    int n;
    cin >> n;
    uniform_int_distribution<int> di2(0, n);
    auto generator = bind(distribution, engine);
    auto geno = bind(di2, engine);
    // 0~100 범위의 난수 100개 생성하여 출력
    for (int i = 0; i < 100; ++i)
        cout << generator() << endl;
}