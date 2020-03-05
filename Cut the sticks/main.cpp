// Cut the sticks
/*
	스틱 배열이 있는데 가장 짧은걸 기준으로 잘라서 버림
	하나 남을 때까지 몇 개씩 남고 있는지 구하기

	ex)
	1,2,3 -> 1로 자름
	1,2 -> 1로 자름
	1 -> 끝
	[3,2,1] 3개 2개 1개

	1 <= n <= 1000 스틱 갯수
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