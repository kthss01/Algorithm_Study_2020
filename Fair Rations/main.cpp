// Fair Rations
/*
	rations 식료품
	benevolent 자애로운
	loaves 빵
	dwindling 줄어드는
	loaf 덩어리

	빵을 줄서있는 사람들에게 나눠주는데 규칙을 가지고 나눠줌
	i번째 사람에게 나눠주면 i-1 or i+1사람에게도 나눠줘야야함
	결국 다 나눠줬을 때 모든 사람이 짝수개의 빵을 가지고 있어야함

	최소한의 빵의 갯수로 규칙을 만족하며 나눠줄 수 있는지 구하기
	불가능하면 NO 출력

	ex)
	[4,5,6,7]
	i=3,4 -> [4,5,7,8]
	i=2,3 -> [4,6,8,8]
	=> 4

	2 <= N <= 1000
	1 <= B[i] <= 10 where 1 <= i <= N
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int fairRations(vector<int> B) {
	int cnt = 0;

	while (true)
	{
		bool bFind = false;
		//  틀림
		//for (int i = 0; i < B.size(); i++) {
		//	if (B[i] % 2 == 0) continue;
		//	// odd odd
		//	if (i > 0 && B[i - 1] % 2 != 0) {
		//		bFind = true;
		//		B[i]++;
		//		B[i - 1]++;
		//		cnt += 2;
		//	}
		//	else if (i < B.size() - 1 && B[i + 1] % 2 != 0) {
		//		bFind = true;
		//		B[i]++;
		//		B[i + 1]++;
		//		cnt += 2;
		//	}
		//	// odd even odd
		//	else if (i > 1 && B[i - 1] % 2 == 0 && B[i - 2] % 2 != 0) {
		//		bFind = true;
		//		B[i]++;
		//		B[i - 1] += 2;
		//		B[i - 2]++;
		//		cnt += 4;
		//	}
		//	else if (i < B.size() - 2 && B[i + 1] % 2 == 0 && B[i + 2] % 2 != 0) {
		//		bFind = true;
		//		B[i]++;
		//		B[i + 1] += 2;
		//		B[i + 2]++;
		//		cnt += 4;
		//	}
		//}

		for (int i = 0; i < B.size() - 1; i++) {
			if (B[i] % 2 == 0) continue;
			bFind = true;
			B[i]++;
			B[i + 1]++;
			cnt += 2;
		}

		if (bFind == false) break;
	}

	for(int i=0; i<B.size(); i++)
		if (B[i] % 2 != 0) {
			cnt = -1;
			break;
		}

	return cnt;
}

int main() {
	int n;
	cin >> n;

	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> b[i];

	int result = fairRations(b);
	cout << (result == -1 ? "NO" : to_string(result)) << endl;

	return 0;
}