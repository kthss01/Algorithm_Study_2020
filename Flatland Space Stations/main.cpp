// Flatland Space Stations
/*
	���ð� �������� ���ڷ� �Ÿ��� �ΰ� �ְ� (��ȯ ������ ����)
	�� ���ÿ��� �ϳ��� ������������ ����
	���� �ϳ��� ���� ����� ������������� �ִ� �Ÿ� ���ϱ�

	ex)
	n = 3
	m = 1

	city 1 = 0
	2 = 2 - 1 = 1
	3 = 3 - 1 = 2 -> �ִ� 2

	1 <= n <= 10^5
	1 <= m <= n
	�ּ� �ϳ��� ������������ �ִ� ���ð� ����
	�� ���ÿ��� ������������ �ϳ��� ����
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