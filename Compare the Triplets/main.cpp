// Compare the Triplets

// triplet 셋으로 된 그룹

/*
	셋으로 된 그룹을 각각 비교해서 한쪽이 크면 해당 쪽이 +1

	ex) a=[1,2,3] b=[3,2,1]

	a[0] > b[0] a++
	a[1] == b[1] 0
	a[2] < b[2] b++

	[1,1] 

	a 3개 b개 입력
	1 <= a[i], b[i] <= 100

	각 점수 출력
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> a(3), b(3);

	for (int i = 0; i < a.size(); i++)
		cin >> a[i];
	for (int i = 0; i < b.size(); i++)
		cin >> b[i];

	vector<int> r(2);

	for (int i = 0; i < a.size(); i++) {
		if (a[i] > b[i]) r[0]++;
		else if (a[i] < b[i]) r[1]++;
	}

	cout << r[0] << ' ' << r[1] << '\n';

	return 0;
}