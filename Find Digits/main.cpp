// Find Digits
/*
	정수 d가 주어질 때 
	그 정수를 하나씩 쪼갠 숫자가 약수가 되는지 확인하기

	ex)
	n = 111,
	1 1 1 다 약수 됨 (따로 취급) -> 3

	1 <= t <= 15
	0 < n < 10^9
*/

#include <iostream>
#include <vector>
using namespace std;

int findDigits(int n) {
	int temp = n;
	int cnt = 0;

	while (temp != 0) {
		if (temp % 10 != 0 && n % (temp % 10) == 0)
			cnt++;
		temp /= 10;
	}

	return cnt;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int result = findDigits(n);
		cout << result << endl;
	}

	return 0;
}