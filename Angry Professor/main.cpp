// Angry Professor
/*
	Discrete �̻�
	Discrete Mathematics �̻� ����
	discipline ¡��, �Ʒ�,
	lack ����

	������ �л��� ���� �� �̻� ������ ���� ����Ϸ��� ��
	�л��� ������ ������ �ð��� �迭�� �־��� ��
	������ ��ҵǴ��� Ȯ���ϱ�

	a[i] <= 0 ���� �°�
	a[i] > 0 ����

	1 <= t <= 10 test cases
	1 <= n <= 1000 �л��� ������ �ð�
	1 <= k <= n ���� �ʾƾ��� �ִ� �л� ��
	-100 <= a[i] <= 100
	ai == 0 �̰� ����

	YES(���) NO(��Ҿƴ�)�� ���
*/

#include <iostream>
#include <vector>
using namespace std;

string angryProfessor(int k, vector<int> a) {
	int cnt = 0;
	for (int temp : a)
		if (temp <= 0)
			cnt++;

	if (cnt < k)
		return "YES"; // ��ҵȴٴ°� k���� ������ �ο��� ���� �ʾƼ�
	else
		return "NO";
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		string result = angryProfessor(k, a);
		cout << result << endl;
	}

	return 0;
}