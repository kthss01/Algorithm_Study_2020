// Viral Advertising
/*
	광고를 공유하고 좋아하는 규칙이 있음
	첫날 5명에 공유하면
	다음 날은 그중 절반 (내림)이 좋아하고 각각 3명의 친구들에게 공유한다고 함
	날짜에 따른 누적 좋아요 구하기

	ex)
	day shared liked cumulative
	1		5		2		2
	2		6		3		5
	3		9		4		9
	4		12		6		15
	5		18		9		24

	1 <= n <= 50
*/

#include <iostream>
#include <vector>
using namespace std;

int viralAdvertising(int n) {
	int shared = 5, liked = 2, cumulative = 2;
	for (int i = 2; i <= n; i++) {
		shared = liked * 3;
		liked = shared / 2;
		cumulative += liked;
	}
	return cumulative;
}

int main() {
	int n;
	cin >> n;

	int result = viralAdvertising(n);
	cout << result << endl;

	return 0;
}