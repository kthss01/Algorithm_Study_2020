// Birthday Chocolate
/*
	array가 있음
	m개를 합해서 d가 되는 갯수를 구하기

	ex)
	s = [2,2,1,3,2]
	d = 4 m = 2
	[2,2] [1,3] -> 2

	1 <= n <= 100
	1 <= s[i] <= 5, (0 <= i < n)
	1 <= d <= 31
	1 <= m <= 12
*/

/*
	해결 방안
	next_permutation 이용해 조합으로 m개를 뽑고 합이 d가 되는지 확인
	뽑은 m개가 같은지도 확인해야할 듯

	-> 문제 잘못이해함 contiguous segement of bar임 연속적인거 찾는거
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//bool isSame(vector<int> a, vector<int> b) {
//	if (a.size() != b.size()) return false;
//
//	for (int i = 0; i < a.size(); i++) {
//		if (a[i] != b[i])
//			return false;
//	}
//
//	return true;
//}
//
//int birthday(vector<int> s, int d, int m) {
//	int count = 0;
//
//	vector<int> ind;
//	for (int i = 0; i < m; i++)
//		ind.push_back(0);
//	for (int i = 0; i < s.size() - m; i++)
//		ind.push_back(1);
//	sort(ind.begin(), ind.end());
//
//	vector< vector<int> > segments;
//
//	do {
//		// 조합 뽑기
//		vector<int> segment;
//		for (int i = 0; i < ind.size(); i++) {
//			if (ind[i] == 0) {
//				segment.push_back(s[i]);
//			}
//		}
//		
//		// 조각 합 확인
//		int sum = 0;
//		for (int num : segment)
//			sum += num;
//		if (sum != d) continue; // 합이 d가 아니면 넘어감
//		
//
//		// 처음 뽑은 조각이면 추가
//		if (segments.size() == 0) {
//			count++;
//			segments.push_back(segment);
//		}
//		else {
//			// 아닌 경우 중복되는지 체크
//			bool bSame = false;
//			for (vector<int> oldSegment : segments) {
//				bSame = isSame(oldSegment, segment);
//				if (bSame == true) break;
//			}
//			if (bSame == false) {
//				count++;
//				segments.push_back(segment);
//			}
//		}
//
//	} while (next_permutation(ind.begin(), ind.end()));
//
//	//// test
//	//for (vector<int> segment : segments) {
//	//	for (int num : segment)
//	//		cout << num << ' ';
//	//	cout << '\n';
//	//}
//
//	return count;
//}

int birthday(vector<int> s, int d, int m) {
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i + m > s.size()) break;
		int sum = 0;
		for (int j = i; j < i + m; j++)
			sum += s[j];
		if (sum == d) count++;
	}
	return count;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int d, m;
	cin >> d >> m;

	cout << birthday(s, d, m);

	return 0;
}