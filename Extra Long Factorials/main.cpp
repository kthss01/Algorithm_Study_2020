// Extra Long Factorials
/*
	�� ���丮�� ���ϱ� 64-bit �Ѿ�°�

	1 <= n <= 100
*/

/*
	bigInteger ������ �������� ������� ���� �� �����ϱ����
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void normalize(vector<int>& num) {
	num.push_back(0);

	// �ڸ��� �ø� ó��
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
	// �ƿ� ���� 0 ����
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

	//// ����� �� �ٽ� ������ ��� ����� ������ �������� �ϱ�
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