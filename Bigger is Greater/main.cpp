// Bigger is Greater
/*
	Lexicographical order 사전 순서

	문자열이 주어졌을 때 문자의 위치를 교환해서 사전순으로 다음이고 그 중 최대한 가까운
	문자 만들기

	w = abcd
	-> abdc
	불가능하면 no answer 출력

	1 <= T <= 10^5 test cases
	1 <= |w| <= 100 (a ~ z 만 무조건 가짐)
*/

/*
	해결방안
	오른쪽에서부터 문자하나가 앞에 문자보다 크면 스왑 (사전순 뒤라는 얘기)
	모두 크지 않아서 맨 앞 문자까지 와버리면 no answer
	맨마지막 문자가 스왑되지 않았으면 다음으로 진행
		맨 처음 스왑된 문자(왼쪽으로 오던 문자) 
	다음부터 반대로 문자하나가 뒤에 문자보다 크면 스왑 (사전순 더 앞이라는 얘기)
	-> 근데 틀리게 나옴 뭔가 문제가 있음
	-> 계속 반복해야할지도 모름
	
	ex)
	dkhc
	hkdc (h > d)

	hdkc (k > d)

	hckd (d > c)
	hcdk (k > d)

	풀이 확인함
	사전식 순열의 다음 항 구하는 알고리즘이 있음 (14세기 인도의 수학자 나라야나 판디타 고안)

	그냥 간단하게 c++ next_permutation 써도 됨
	그래도 공부겸 사전식 순열 생성 알고리즘 구현은 해보자
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
	// 직접 구현
	if (NextPermutation(w)) return w;
	else return "no answer";

	//// algorithm 라이브러리
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