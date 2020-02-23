// Bon Appetit - ���� �弼��
/*
	���� �����ϴµ� ����� �Ȱ��� ������ �ϱ�� ��
	�� ����� �˷����� �ִ°Ÿ� ��ų ��� �� ����� �װ� ��� ����
	
	�����ϰ� ���Ǿ����� Bon Appetit ���
	�ƴϸ� �˷������ ���Դ� ������� �� ��������ϴ��� ���

	2 <= n <= 10^5
	0 <= k < n
	0 <= biil[i] <= 10^4
	0 <= b <= sum(bill[i]) 0 ~ n-1
	������ ���� ������ ����
*/

/*
	allergic �˷�����
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void bonAppetit(vector<int> bill, int k, int b)
{
	bill.erase(bill.begin() + k);

	int charge = accumulate(bill.begin(), bill.end(), 0) / 2;
	if (charge == b)
		cout << "Bon Appetit\n";
	else
		cout << b - charge << '\n';
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> bill(n);
	for (int i = 0; i < n; i++)
		cin >> bill[i];

	int b;
	cin >> b;

	bonAppetit(bill, k, b);

	return 0;
}