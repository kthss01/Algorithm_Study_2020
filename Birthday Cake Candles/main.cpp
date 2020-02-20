// Birthday Cake Candles

// niece ��ī��

/*
	�к� ���� ū�Ÿ� �� �� ���� �� �� �� �� �ִ��� ã��
	
	ex) 4 4 1 3 -> 4�� ���� -> 2

	1 <= n <= 10^5
	1 <= ar[i] <= 10^7
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	vector<int> ar(n);
	int tallest = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		//if (ar[i] > tallest) 
		//	tallest = ar[i];
		tallest = max(ar[i], tallest);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ar[i] == tallest)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}
