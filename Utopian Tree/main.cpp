// Utopian Tree
/*
	������ �ڶ�� ��Ģ�� ���� 2 ����Ŭ�� ���ư��µ�
	ù ����Ŭ�� ������ 2�谡 ��
	���� ����Ŭ�� 1 ���� ����

	ex)
	0 1
	1 2
	2 3
	3 6
	4 7
	5 14
	�̷� ��

	n�� �־����� �� ���� ������ ���ϱ�

	1 <= t <= 10 test case
	0 <= n <= 60
*/

#include <iostream>
#include <vector>
using namespace std;

int utopianTree(int n) {
	static vector<int> heights;

	if (heights.size() == 0) {
		heights.push_back(1);
		for (int i = 1; i <= 60; i++) {
			if (i % 2 == 0)
				heights.push_back(heights[i - 1] + 1);
			else
				heights.push_back(heights[i - 1] * 2);
		}
	}
	
	return heights[n];
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		int result = utopianTree(n);
		cout << result << '\n';
	}

	return 0;
}