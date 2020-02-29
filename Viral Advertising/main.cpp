// Viral Advertising
/*
	���� �����ϰ� �����ϴ� ��Ģ�� ����
	ù�� 5�� �����ϸ�
	���� ���� ���� ���� (����)�� �����ϰ� ���� 3���� ģ���鿡�� �����Ѵٰ� ��
	��¥�� ���� ���� ���ƿ� ���ϱ�

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