// Birthday Chocolate
/*
	array�� ����
	m���� ���ؼ� d�� �Ǵ� ������ ���ϱ�

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
	�ذ� ���
	next_permutation �̿��� �������� m���� �̰� ���� d�� �Ǵ��� Ȯ��
	���� m���� �������� Ȯ���ؾ��� ��

	-> ���� �߸������� contiguous segement of bar�� �������ΰ� ã�°�
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
//		// ���� �̱�
//		vector<int> segment;
//		for (int i = 0; i < ind.size(); i++) {
//			if (ind[i] == 0) {
//				segment.push_back(s[i]);
//			}
//		}
//		
//		// ���� �� Ȯ��
//		int sum = 0;
//		for (int num : segment)
//			sum += num;
//		if (sum != d) continue; // ���� d�� �ƴϸ� �Ѿ
//		
//
//		// ó�� ���� �����̸� �߰�
//		if (segments.size() == 0) {
//			count++;
//			segments.push_back(segment);
//		}
//		else {
//			// �ƴ� ��� �ߺ��Ǵ��� üũ
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