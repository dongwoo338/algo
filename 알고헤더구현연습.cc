#include<iostream>
#include<vector>
using namespace std;
template<class InputIterator, class UnaryPredicate>
bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
	while (first != last) {
		if (!pred(*first))return 0;
		first++;
	}
	return 1;
}
bool isprime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return 0;
	}
	return 1;
}
template<class Iter>
bool is_sorted(Iter now, Iter last){
	auto prev = now++;
	while (now != last) {
		if (*now < *prev)return 0;
		prev = now++;
	}
	return 1;
}

// match now itearator that matchs(now,next),  else return last iteroator
bool isonbitdiff(int a, int b) {
	if (a + b == (a ^ b))return 1;
	return 0;
}
template<class Iter, class Predicat>
// if now and next matches predicates reutrn iterator
Iter adjacent_find(Iter now, Iter last, Predicat P) {
	auto prev = now++;
	while (now != last) {
		if (P(*prev, *now))return prev;
		prev = now++;
	}
	return last;
}
int main() {
	vector<int> v = { 1,3 };
	//cout << all_of(v.begin(), v.end(), isprime);
	//cout << is_sorted(v.begin(), v.end());
	//auto it = adjacent_find(v.begin(), v.end(), isonbitdiff);
	//cout << *it;

}