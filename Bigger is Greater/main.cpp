// Bigger is Greater
/*
	Lexicographical order ���� ����

	���ڿ��� �־����� �� ������ ��ġ�� ��ȯ�ؼ� ���������� �����̰� �� �� �ִ��� �����
	���� �����

	w = abcd
	-> abdc
	�Ұ����ϸ� no answer ���

	1 <= T <= 10^5 test cases
	1 <= |w| <= 100 (a ~ z �� ������ ����)
*/

/*
	�ذ���
	�����ʿ������� �����ϳ��� �տ� ���ں��� ũ�� ���� (������ �ڶ�� ���)
	��� ũ�� �ʾƼ� �� �� ���ڱ��� �͹����� no answer
	�Ǹ����� ���ڰ� ���ҵ��� �ʾ����� �������� ����
		�� ó�� ���ҵ� ����(�������� ���� ����) 
	�������� �ݴ�� �����ϳ��� �ڿ� ���ں��� ũ�� ���� (������ �� ���̶�� ���)
	-> �ٵ� Ʋ���� ���� ���� ������ ����
	-> ��� �ݺ��ؾ������� ��
	
	ex)
	dkhc
	hkdc (h > d)

	hdkc (k > d)

	hckd (d > c)
	hcdk (k > d)

	Ǯ�� Ȯ����
	������ ������ ���� �� ���ϴ� �˰����� ���� (14���� �ε��� ������ ����߳� �ǵ�Ÿ ���)

	�׳� �����ϰ� c++ next_permutation �ᵵ ��
	�׷��� ���ΰ� ������ ���� ���� �˰��� ������ �غ���
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool NextPermutation(string& s) {
	// Find logest non-increasing suffix
	int i = s.length() - 1;
	while (i > 0 && s[i - 1] >= s[i]) i--;
	// Now i is the head index of the suffix

	if (i <= 0) return false;

	// arr[i-1] be the pivot
	// Find rightmost element that exceeds the pivot
	int j = s.length() - 1;
	while (s[j] <= s[i - 1]) j--;
	// arr[j] new pivto
	// Assertion: j >= i

	// swap pivot j
	int temp = s[i - 1];
	s[i - 1] = s[j];
	s[j] = temp;

	// reverse the suffix
	j = s.length() - 1;
	while (i < j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}

	return true;
}

string biggerIsGreater(string w) {
	// ���� ����
	if (NextPermutation(w)) return w;
	else return "no answer";

	//// algorithm ���̺귯��
	//if (next_permutation(w.begin(), w.end()) == false)
	//	return "no answer";
	//else
	//	return w;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string w;
		cin >> w;

		string result = biggerIsGreater(w);

		cout << result << '\n';
	}

	return 0;
}