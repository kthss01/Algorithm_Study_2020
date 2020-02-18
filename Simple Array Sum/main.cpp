// Simple Array Sum

/*
	Given an array of integers, find the sum of its elements
	ex ar = [1,2,3] => 1+2+3 = 6, so return 6

	0 < n, ar[i] <= 1000
*/

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int e;
		cin >> e;
		ans += e;
	}

	cout << ans << '\n';

	return 0;
}