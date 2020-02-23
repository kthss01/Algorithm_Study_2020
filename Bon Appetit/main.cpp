// Bon Appetit - 많이 드세요
/*
	둘이 시작하는데 계산을 똑같이 나눠서 하기로 함
	한 사람은 알레르기 있는거를 시킬 경우 그 사람은 그건 계산 안함
	
	공평하게 계산되었으면 Bon Appetit 출력
	아니면 알레르기라 못먹는 사람에게 얼마 돌려줘야하는지 출력

	2 <= n <= 10^5
	0 <= k < n
	0 <= biil[i] <= 10^4
	0 <= b <= sum(bill[i]) 0 ~ n-1
	돌려줄 값은 언제나 정수
*/

/*
	allergic 알레르기
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