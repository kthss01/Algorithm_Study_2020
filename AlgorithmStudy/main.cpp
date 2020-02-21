#include <iostream>
#include <vector>
#include <algorithm>
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

	// ���� (next_permutation �Լ� �̿�)
	void Permutation() {
		/*
			�ߺ��� �ִ� ���ҵ��� ���
			�ߺ��� ��츦 �����ϰ� ������ �������
		*/
		vector<int> v;
		//for (int i = 0; i < 4; i++)
		//	v.push_back(i + 1);

		v.push_back(0);
		v.push_back(1);
		v.push_back(1);

		sort(v.begin(), v.end());

		// ����
		do {
			// ���
			for (int ele : v)
				cout << ele << ' ';
			cout << '\n';
		} while (next_permutation(v.begin(), v.end()));
	}

	// ���� (next_permutation �Լ� �̿�)
	void Combination() {
		/*
			��ü n���� ���ҵ� �߿��� k���� �̴� ����(=nCk)�� ���Ѵٸ�
			n���� ���� ���ҿ� 1�� k�� 0�� �������� n-k�� ����־
			������ ������ 1�� �ش��ϴ� �ε����� �������� ��
		*/

		// nCk ����
		int n = 6;
		int k = 4;
		vector<int> v;
		// 1 ~ n���� ����
		for (int i = 0; i < n; i++)
			v.push_back(i + 1);

		// 0�� 1�� ������ ���� ����
		vector<int> ind;
		// k���� 1 �߰�
		for (int i = 0; i < k; i++)
			ind.push_back(1);
		// n-k���� 0 �߰�
		for (int i = 0; i < v.size() - k; i++)
			ind.push_back(0);

		sort(ind.begin(), ind.end());

		// ����
		do {
			// ���
			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 1) {
					cout << v[i] << ' ';
				}
			}
			cout << '\n';
		} while (next_permutation(ind.begin(), ind.end()));
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Algorithm algorithm;

	// gcd ����
	//int gcd = algorithm.GCD(12, 32);
	//cout << "GCD " << gcd << '\n';

	// ���� ����
	//algorithm.Permutation();
	
	// ���� ����
	algorithm.Combination();

	return 0;
}