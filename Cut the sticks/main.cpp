// Cut the sticks
/*
	��ƽ �迭�� �ִµ� ���� ª���� �������� �߶� ����
	�ϳ� ���� ������ �� ���� ���� �ִ��� ���ϱ�

	ex)
	1,2,3 -> 1�� �ڸ�
	1,2 -> 1�� �ڸ�
	1 -> ��
	[3,2,1] 3�� 2�� 1��

	1 <= n <= 1000 ��ƽ ����
	1 <= arr[i] <= 1000
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cutTheSticks(vector<int> arr) {
	sort(arr.begin(), arr.end(), greater<int>());

	vector<int> cnt;

	int t = 0;
	while (true) {
		cnt.push_back(arr.size());
		if (arr.size() == 1) break;
		t = arr.back();
		while (t == arr.back()) {
			arr.pop_back();
			if (arr.size() == 0) break;
		}
		if (arr.size() == 0) break;
	}

	return cnt;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> result = cutTheSticks(arr);

	for(int ele : result)
		cout << ele << endl;

	return 0;
}