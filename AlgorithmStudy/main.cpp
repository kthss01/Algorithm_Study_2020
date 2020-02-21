#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Algorithm
{
public:
	// 최대공약수(GCD) 유클리드 알고리즘
	int GCD(int a, int b) {
		/*
			GCD (greatest common divisor)
			유클리드 알고리즘 원리
			임의의 두 자연수 a,b가 주어졌을 때, 둘 중 큰 값이 a라고 가정
			a를 b로 나눈 나머지를 n 이라고 하면 (a%b = n)
			n=0 일때, b가 최대공약수(GCD)
			만약 n이 0이 아니라면, a에 b값을 다시 넣고 n를 b에 대입 한 후 다시 반복
		*/

		//// 반복문 이용
		//int tmp, n;
		//
		//// a에 큰 값 위치
		//if (a < b) {
		//	tmp = a;
		//	a = b;
		//	b = tmp;
		//}

		//// b가 0이 될 때까지(a%b), 반복문, b가 0인 순간 a GCD
		//while (b != 0) {
		//	n = a % b;
		//	a = b;
		//	b = n;
		//}
		//return a;

		// 재귀함수(recursive) 이용
		if (b == 0)
			return a;
		else
			return GCD(b, a % b);
	}

	// 최소공배수(LCM)
	int LCD(int a, int b) {
		/*
			(최소공배수 x 최대공약수 = a x b)를 이용
			a x b / gcd(a,b)
		*/

		return a * b / GCD(a, b);
	}

	// 순열 (next_permutation 함수 이용)
	void Permutation() {
		/*
			중복이 있는 원소들의 경우
			중복인 경우를 제외하고 순열을 만들어줌
		*/
		vector<int> v;
		//for (int i = 0; i < 4; i++)
		//	v.push_back(i + 1);

		v.push_back(0);
		v.push_back(1);
		v.push_back(1);

		sort(v.begin(), v.end());

		// 순열
		do {
			// 출력
			for (int ele : v)
				cout << ele << ' ';
			cout << '\n';
		} while (next_permutation(v.begin(), v.end()));
	}

	// 조합 (next_permutation 함수 이용)
	void Combination() {
		/*
			전체 n개의 원소들 중에서 k개를 뽑는 조합(=nCk)을 구한다면
			n개의 벡터 원소에 1을 k개 0을 나머지인 n-k개 집어넣어서
			순열을 돌리고 1에 해당하는 인덱스만 가져오면 됨
		*/

		// nCk 조합
		int n = 6;
		int k = 4;
		vector<int> v;
		// 1 ~ n까지 생성
		for (int i = 0; i < n; i++)
			v.push_back(i + 1);

		// 0과 1을 저장할 벡터 생성
		vector<int> ind;
		// k개의 1 추가
		for (int i = 0; i < k; i++)
			ind.push_back(1);
		// n-k개의 0 추가
		for (int i = 0; i < v.size() - k; i++)
			ind.push_back(0);

		sort(ind.begin(), ind.end());

		// 순열
		do {
			// 출력
			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 1) {
					cout << v[i] << ' ';
				}
			}
			cout << '\n';
		} while (next_permutation(ind.begin(), ind.end()));
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Algorithm algorithm;

	// gcd 예제
	//int gcd = algorithm.GCD(12, 32);
	//cout << "GCD " << gcd << '\n';

	// 순열 예제
	//algorithm.Permutation();
	
	// 조합 예제
	algorithm.Combination();

	return 0;
}