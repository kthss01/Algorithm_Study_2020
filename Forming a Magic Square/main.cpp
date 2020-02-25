// Forming a Magic Square
/*
	�������� �޾Ƽ� �ٲٴµ�
	1 ~ 9�� �ٵ��� �ٲٷ���
	�� �� �ٲٰ� �Ǵ� ���� ���� �� ���ϱ�

	�ذ� ���
	3x3 �̸� 
	n �� 3�� ���
	���� (n^3 + 3) / 2 = 15 �̾���Ѵٰ� �� (��Ű���)

	15�� �ǵ��� ����� ��

	ã�ƺ���
	3x3 �������� 8�� �ۿ� ����
	�ϳ��� �������� rotate reflection �ؼ� ��������Ŷ�� ��

	8���� ���ؼ� cost ���� ������ ã���� �� �� ����
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findCost(vector<vector<int>> s, vector<vector<int>> m)
{
	int cost = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cost += abs(s[i][j] - m[i][j]);
	return cost;
}

int formingMagicSquare(vector<vector<int>> s) {
	vector<vector<vector<int>>> ms = {
	{{8,1,6},{3,5,7},{4,9,2}},
	{{6,1,8},{7,5,3},{2,9,4}},
	{{4,9,2},{3,5,7},{8,1,6}},
	{{2,9,4},{7,5,3},{6,1,8}},
	{{8,3,4},{1,5,9},{6,7,2}},
	{{4,3,8},{9,5,1},{2,7,6}},
	{{6,7,2},{1,5,9},{8,3,4}},
	{{2,7,6},{9,5,1},{4,3,8}}};

	int minCost = 0;

	for (int i = 0; i < 8; i++) {
		if (i == 0)
			minCost = findCost(s, ms[i]);
		else
			minCost = min(minCost, findCost(s, ms[i]));
	}

	return minCost;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<int>> s(3);

	for (int i = 0; i < 3; i++) {
		s[i].resize(3);
		for (int j = 0; j < 3; j++)
			cin >> s[i][j];
	}

	int result = formingMagicSquare(s);

	cout << result << '\n';

	return 0;
}