// Beautiful Days at the Movies
/*
	evenly ����

	���� ������ �־����� ���� �ϳ��� �־��� ��
	�� ���ڿ� �� ���ڸ� ������ ������ ���� ���밪�� ���� �ϳ��� ���������� �˾ƺ���
	�������� ������ ���� ���ϱ�

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