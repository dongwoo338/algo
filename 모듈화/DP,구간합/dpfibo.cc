#include<bits/stdc++.h>
using namespace std;

int cnt; //  함수 호출 횟수
const int N = 2501;// 문제에서 요구하는 것보다 충분히 크게
int dp[N];
int fibo(int i) { // i번째 피보나치 수를 구하는 함수
	
	// 기저 사례
	if (i == 0)return 0;
	if (i == 1)return 1;
	
	// 메모이제이션 단계
	int &ret = dp[i];
	if (ret != -1)return ret;

	// 점화식 단계
	ret = fibo(i - 1) + fibo(i - 2);
	return ret;
}

int main() {
	// 문제를 풀면서 절대 나올수 없는 값으로
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	cout << fibo(n);
}