// Beautiful Days at the Movies
/*
	evenly 고르게

	숫자 범위가 주어지고 숫자 하나가 주어질 때
	그 숫자와 그 숫자를 뒤집은 숫자의 차의 절대값이 숫자 하나로 나눠지는지 알아보기
	나눠지는 숫자의 갯수 구하기

	1 <= i <= j <= 2 x 10^6
	1 <= k <= 2 x 10^9
*/

#include <iostream>
using namespace std;

int reverseNum(int n) {
	int result = 0;
	while (n != 0) {
		result *= 10;
		result += n % 10;
		n /= 10;
	}
	return result;
}

int beautifulDays(int i, int j, int k) {
	int cnt = 0;
	for (int day = i; day <= j; day++) {
		if (abs(day - reverseNum(day)) % k == 0)
			cnt++;
	}
	return cnt;
}

int main() {
	int i, j, k;
	cin >> i >> j >> k;

	int result = beautifulDays(i, j, k);
	cout << result << endl;

	return 0;
}