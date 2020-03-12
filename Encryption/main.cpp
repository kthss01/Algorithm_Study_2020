// Encryption
/*
	encryption ��ȣȭ
	scheme ��ȹ

	���ڿ��� �־��� �� ��ȣȭ�� �ؼ� ����ϸ� ��
	
	��Ģ
	���ڿ� ���� L�̶� �� ��
	root L(����) <= row <= column <= root L(�ø�)
	�� �� ���⼭ ������ ���� ���� ���� ����
	(rows x columns >= L ����, ������ �� ��� ���� ���� �� ����)

	ex) L 54
	7 ~ 8
	row 7 column 8
	
	�� ������ ��� �ϰ� �����̽� �߰��ϴ� ������ �ϼ�

	ex)
	ifmanwas
	meanttos
	tayonthe
	groundgo
	dwouldha
	vegivenu
	sroots

	imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau

	1 <= |s| <= 81 ���ڿ� ���� (a ~ z��)
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
