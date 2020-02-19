// Staircase
/*
	별 만들기
	   #
	  ##
	 ###
	####
	와 같은방식으로 만들기

	0 < n <= 100
*/

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = n; j > i + 1; j--)
			cout << ' ';
		for (int j = 0; j <= i; j++)
			cout << '#';
		cout << '\n';
	}

	return 0;
}