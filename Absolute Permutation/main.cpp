// Absolute Permutation
/*
	��Ģ�� �°� ������ �����

	��Ģ
	n������ ���� (1����) k ���밪 ���̷� ������ �����
	������ �ȵǸ� -1 ���
	
	ex)
	n = 4 k = 2
	p = [1,2,3,4]
	-> 3,4,1,2
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> absolutePermutation(int n, int k) {
	vector<bool> check(n + 1);
	vector<int> result;

	for (int i = 1; i <= n; i++) {
		if (i - k > 0 && check[i - k] == false) {
			check[i - k] = true;
			result.push_back(i - k);
		}
		else if (i + k <= n && check[i + k] == false) {
			check[i + k] = true;
			result.push_back(i + k);
		}
		else {
			result.clear();
			result.push_back(-1);
			break;
		}
	}

	return result;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> result = absolutePermutation(n, k);

		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
			if (i != result.size() - 1) cout << " ";
		}

		cout << endl;
	}

	return 0;
}