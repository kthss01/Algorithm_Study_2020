// Encryption
/*
	encryption 암호화
	scheme 계획

	문자열이 주어질 때 암호화를 해서 출력하면 됨
	
	규칙
	문자열 길이 L이라 할 때
	root L(내림) <= row <= column <= root L(올림)
	한 후 여기서 공간이 가장 작은 값을 구함
	(rows x columns >= L 보장, 여러개 일 경우 가장 작은 값 선택)

	ex) L 54
	7 ~ 8
	row 7 column 8
	
	열 순으로 출력 하고 스페이스 추가하는 식으로 완성

	ex)
	ifmanwas
	meanttos
	tayonthe
	groundgo
	dwouldha
	vegivenu
	sroots

	imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau

	1 <= |s| <= 81 문자열 길이 (a ~ z만)
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string encryption(string s) {
	int l = s.length();

	int minV = round(sqrt(l));
	int maxV = ceil(sqrt(l));
	int row, col;

	if (minV * minV >= l)
		row = col = minV;
	else if (minV * maxV >= l) {
		row = minV;
		col = maxV;
	}
	else
		row = col = maxV;
	
	string r = "";

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (i + j * col >= l) continue;
			r += s[i + j * col];
		}
		r += " ";
	}

	return r;
}

int main() {
	string s;
	cin >> s;

	string result = encryption(s);

	cout << result << endl;

	return 0;
}
