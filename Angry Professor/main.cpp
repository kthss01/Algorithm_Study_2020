// Angry Professor
/*
	Discrete 이산
	Discrete Mathematics 이산 수학
	discipline 징계, 훈련,
	lack 부족

	수업에 학생이 일정 수 이상 늦으면 수업 취소하려고 함
	학생들 수업에 도착한 시간이 배열로 주어질 때
	수업이 취소되는지 확인하기

	a[i] <= 0 일찍 온거
	a[i] > 0 지각

	1 <= t <= 10 test cases
	1 <= n <= 1000 학생이 도착한 시간
	1 <= k <= n 늦지 않아야할 최대 학생 수
	-100 <= a[i] <= 100
	ai == 0 이건 인정

	YES(취소) NO(취소아님)로 출력
*/

#include <iostream>
#include <vector>
using namespace std;

string angryProfessor(int k, vector<int> a) {
	int cnt = 0;
	for (int temp : a)
		if (temp <= 0)
			cnt++;

	if (cnt < k)
		return "YES"; // 취소된다는거 k보다 부족한 인원이 늦지 않아서
	else
		return "NO";
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		string result = angryProfessor(k, a);
		cout << result << endl;
	}

	return 0;
}