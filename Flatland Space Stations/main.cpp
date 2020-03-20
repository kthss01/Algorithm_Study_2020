// Flatland Space Stations
/*
	도시가 연속적인 숫자로 거리를 두고 있고 (순환 되지는 않음)
	그 도시에는 하나의 우주정거장이 있음
	도시 하나와 가장 가까운 우주정거장과의 최대 거리 구하기

	ex)
	n = 3
	m = 1

	city 1 = 0
	2 = 2 - 1 = 1
	3 = 3 - 1 = 2 -> 최대 2

	1 <= n <= 10^5
	1 <= m <= n
	최소 하나의 우주정거장이 있는 도시가 있음
	한 도시에는 우주정거장은 하나만 있음
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int flatlandSpaceStations(int n, vector<int> c)
{
	sort(c.begin(), c.end());

	vector<int> nearest;

	for (int i = 0; i < n; i++) {
		int temp = abs(i-c[0]);
		for (int j = 1; j < c.size(); j++) {
			temp = min(abs(i - c[j]), temp);
		}
		nearest.push_back(temp);
	}

	int ans = 0;
	for (int i = 0; i < nearest.size(); i++)
		ans = max(ans, nearest[i]);

	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> c(m);
	for (int i = 0; i < m; i++)
		cin >> c[i];

	int result = flatlandSpaceStations(n, c);
	cout << result << endl;

	return 0;
}