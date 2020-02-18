// A Very Big Sum

/*
	아주 큰 수 더 하기
	1 <= n <= 10
	0 <= ar[i] <= 10^10
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		long long int ele;
		cin >> ele;
		ans += ele;
	}

	cout << ans << '\n';

	return 0;
}