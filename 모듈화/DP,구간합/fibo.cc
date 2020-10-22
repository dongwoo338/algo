#include<bits/stdc++.h>
using namespace std;

int cnt; //  함수 호출 횟수
int fibo(int i) { // i번째 피보나치 수를 구하는 함수
	cnt++;
	// 기저 사례
	if (i == 0)return 0;
	if (i == 1)return 1;

	// 점화식 단계
	int ret = fibo(i - 1) + fibo(i - 2);
	return ret;
}

int main() {
	cout << fibo(5) << "\n";
	cout << cnt << "\n";
}