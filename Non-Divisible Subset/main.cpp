// Non-Divisible Subset
/*
	집합이 있는데 그 집합의 두 원소의 합이 k로 나눠지지 않는 부분집합을 구하기
	
	1 <= n <= 10^5
	1 <= k <= 100
	1 <= s[i] <= 10^9
	주어진 숫자는 다 다름
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
6 4
19 10 12 24 25 22
*/

int nonDivisibleSubset(int k, vector<int> s) {
	// 이해를 위해서 테스트 해본거 정답과는 조금 다른듯
	//vector<int> ind;
	//ind.push_back(0);
	//ind.push_back(0);
	//for (int i = 0; i < s.size() - 2; i++)
	//	ind.push_back(1);

	//do {
	//	int sum = 0;
	//	int cnt = 0;
	//	for (int i = 0; i < ind.size(); i++) {
	//		if (ind[i] == 0) {
	//			cnt = (cnt + 1) % 2;
	//			cout << s[i] << "(" << s[i] % k << ")";
	//			if (cnt == 1) cout << " + ";
	//			sum += s[i];
	//		}
	//	}
	//	cout << " = " << sum << "(" << sum % k << ")";
	//	if (sum % k == 0) cout << "(Divisible)";
	//	cout << endl;

	//} while (next_permutation(ind.begin(), ind.end()));

	/*
		풀이를 봤는데 영어라 간단히 정리
		각 숫자들의 나머지로만 보았을 때로 구분함
		각 숫자의 나머지의 합에 따라 나눠지고 안나눠지는게 구분됨
		ex) 
		6 4
		19 10 12 24 25 22
		-> 3 2 0 0 1 2
		k가 4인 경우
		나머지가 1일땐 3과 합해야 나머지가 4가되서 나눠 떨어짐
		2일 땐 2와
		0일 때는 스페셜 케이스로 0 0인 경우만 가능함
		ex2)
		k가 5면 
		1-4 2-3 가능하고 0-0 가능하다는 얘기
		다시말해 가장 큰 부분 집합을 구할 때
		1과 4 중 더 큰 값들 선택
		2와 3 중 더 큰 값 선택
		0같은 경우는 1,2,3,4에 다 들어가 있기 때문에 +1만 해주면 됨 (0 하나만 뽑으면 되니까)

		ex3)
		k가 6일때 (짝수인 경우는 0이랑 비슷함) 
		3의경우 (3+3) 역시 +1만 해주면 됨 (3 역시 다들어가있음)
	*/

	vector< vector<int> > d(k);
	for (int i = 0; i < s.size(); i++)
		d[s[i] % k].push_back(s[i]);

	int count = 0;

	if (d[0].size() > 0) count++;

	for (int i = 1; i <= k / 2; i++) {
		int j = k - i;
		if (i != j)
			count += max(d[i].size(), d[k - i].size());
		else
			if (d[i].size() > 0) count += 1;
	}

	return count;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int result = nonDivisibleSubset(k, s);
	cout << result << endl;

	return 0;
}