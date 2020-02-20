// Mini-Max Sum
/*
	5�� ���ڸ� �޾� ���� ���� 4���� �հ� ���� ū 4���� �� ���ϱ�
	1 <= arr[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> arr(5);
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	long long int minSum = 0, maxSum = 0;
	for (int i = 0; i < 5; i++) {
		if (i != 0) maxSum += arr[i];
		if (i != 4) minSum += arr[i];
	}

	cout << minSum << ' ' << maxSum << '\n';

	return 0;
}