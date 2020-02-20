#include <iostream>
using namespace std;

class Algorithm
{
public:
	// �ִ�����(GCD) ��Ŭ���� �˰���
	int GCD(int a, int b) {
		/*
			GCD (greatest common divisor)
			��Ŭ���� �˰��� ����
			������ �� �ڿ��� a,b�� �־����� ��, �� �� ū ���� a��� ����
			a�� b�� ���� �������� n �̶�� �ϸ� (a%b = n)
			n=0 �϶�, b�� �ִ�����(GCD)
			���� n�� 0�� �ƴ϶��, a�� b���� �ٽ� �ְ� n�� b�� ���� �� �� �ٽ� �ݺ�
		*/

		//// �ݺ��� �̿�
		//int tmp, n;
		//
		//// a�� ū �� ��ġ
		//if (a < b) {
		//	tmp = a;
		//	a = b;
		//	b = tmp;
		//}

		//// b�� 0�� �� ������(a%b), �ݺ���, b�� 0�� ���� a GCD
		//while (b != 0) {
		//	n = a % b;
		//	a = b;
		//	b = n;
		//}
		//return a;

		// ����Լ�(recursive) �̿�
		if (b == 0)
			return a;
		else
			return GCD(b, a % b);
	}

	// �ּҰ����(LCM)
	int LCD(int a, int b) {
		/*
			(�ּҰ���� x �ִ����� = a x b)�� �̿�
			a x b / gcd(a,b)
		*/

		return a * b / GCD(a, b);
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Algorithm algorithm;

	// gcd ����
	int gcd = algorithm.GCD(12, 32);
	cout << "GCD " << gcd << '\n';

	return 0;
}