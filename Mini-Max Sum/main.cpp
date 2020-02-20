// Mini-Max Sum
/*
	5개 숫자를 받아 가장 작은 4개의 합과 가장 큰 4개의 합 구하기
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