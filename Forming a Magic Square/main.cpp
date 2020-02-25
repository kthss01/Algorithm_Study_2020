// Forming a Magic Square
/*
	마방진을 받아서 바꾸는데
	1 ~ 9가 다들어가게 바꾸려함
	그 때 바꾸게 되는 숫자 차의 합 구하기

	해결 방안
	3x3 이면 
	n 이 3인 경우
	합은 (n^3 + 3) / 2 = 15 이어야한다고 함 (위키백과)

	15가 되도록 만들면 됨

	찾아보니
	3x3 마방진은 8개 밖에 없고
	하나의 마방진을 rotate reflection 해서 만들어진거라고 함

	8개랑 비교해서 cost 제일 적은거 찾으면 될 것 같음
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