// Non-Divisible Subset
/*
	������ �ִµ� �� ������ �� ������ ���� k�� �������� �ʴ� �κ������� ���ϱ�
	
	1 <= n <= 10^5
	1 <= k <= 100
	1 <= s[i] <= 10^9
	�־��� ���ڴ� �� �ٸ�
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
6 4
19 10 12 24 25 22
*/

int nonDivisibleSubset(int k, vector<int> s) {
	// ���ظ� ���ؼ� �׽�Ʈ �غ��� ������� ���� �ٸ���
	//vector<int> ind;
	//ind.push_back(0);
	//ind.push_back(0);
	//for (int i = 0; i < s.size() - 2; i++)
	//	ind.push_back(1);

	//do {
	//	int sum = 0;
	//	int cnt = 0;
	//	for (int i = 0; i < ind.size(); i++) {
	//		if (ind[i] == 0) {
	//			cnt = (cnt + 1) % 2;
	//			cout << s[i] << "(" << s[i] % k << ")";
	//			if (cnt == 1) cout << " + ";
	//			sum += s[i];
	//		}
	//	}
	//	cout << " = " << sum << "(" << sum % k << ")";
	//	if (sum % k == 0) cout << "(Divisible)";
	//	cout << endl;

	//} while (next_permutation(ind.begin(), ind.end()));

	/*
		Ǯ�̸� �ôµ� ����� ������ ����
		�� ���ڵ��� �������θ� ������ ���� ������
		�� ������ �������� �տ� ���� �������� �ȳ������°� ���е�
		ex) 
		6 4
		19 10 12 24 25 22
		-> 3 2 0 0 1 2
		k�� 4�� ���
		�������� 1�϶� 3�� ���ؾ� �������� 4���Ǽ� ���� ������
		2�� �� 2��
		0�� ���� ����� ���̽��� 0 0�� ��츸 ������
		ex2)
		k�� 5�� 
		1-4 2-3 �����ϰ� 0-0 �����ϴٴ� ���
		�ٽø��� ���� ū �κ� ������ ���� ��
		1�� 4 �� �� ū ���� ����
		2�� 3 �� �� ū �� ����
		0���� ���� 1,2,3,4�� �� �� �ֱ� ������ +1�� ���ָ� �� (0 �ϳ��� ������ �Ǵϱ�)

		ex3)
		k�� 6�϶� (¦���� ���� 0�̶� �����) 
		3�ǰ�� (3+3) ���� +1�� ���ָ� �� (3 ���� �ٵ�����)
	*/

	vector< vector<int> > d(k);
	for (int i = 0; i < s.size(); i++)
		d[s[i] % k].push_back(s[i]);

	int count = 0;

	if (d[0].size() > 0) count++;

	for (int i = 1; i <= k / 2; i++) {
		int j = k - i;
		if (i != j)
			count += max(d[i].size(), d[k - i].size());
		else
			if (d[i].size() > 0) count += 1;
	}

	return count;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int result = nonDivisibleSubset(k, s);
	cout << result << endl;

	return 0;
}