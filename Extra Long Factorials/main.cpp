// Extra Long Factorials
/*
	긴 팩토리얼 구하기 64-bit 넘어가는거

	1 <= n <= 100
*/

/*
	bigInteger 구현이 생각보다 어려워서 조사 후 구현하기로함
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void normalize(vector<int>& num) {
	num.push_back(0);

	// 자릿수 올림 처리
	int size = num.size();
	for (int i = 0; i < size - 1; i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else
		{
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	// 아에 남은 0 제거
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}

vector<int> multiply(vector<int> a, vector<int> b) {
	vector<int> c(a.size() + b.size() + 1, 0);

	int aSize = a.size();
	int bSize = b.size();

	for (int i = 0; i < aSize; i++)
		for (int j = 0; j < bSize; j++)
			c[i + j] += a[i] * b[j];
	normalize(c);

	//// 연산된 값 다시 뒤집기 모든 계산이 끝나고 마지막에 하기
	//reverse(c.begin(), c.end());

	return c;
}

void extraLongFactorials(int n) {
	long long l = 1;
	
	if (n <= 20) {
		for (int i = 2; i <= n; i++) l *= i;
		cout << l << endl;
	}
	else {
		for (int i = 2; i <= 20; i++) l *= i;

		vector<int> a;
		while (l != 0) {
			a.push_back(l % 10);
			l /= 10;
		}

		for (int i = 21; i <= n; i++) {
			vector<int> b;
			int t = i;
			while (t != 0) {
				b.push_back(t % 10);
				t /= 10;
			}
			a = multiply(a, b);
		}

		reverse(a.begin(), a.end());
		for (int i = 0; i < a.size(); i++)
			cout << a[i];
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;

	extraLongFactorials(n);

	return 0;
}