// 3D Surface Area
/*
	3차원 도형이 주어졌을 때
	표면적의 값 구하기

	3차원 도형을 2차원 형태로 row col과 각 cell의 높이로 주어짐
	그렇게 주어졌을 때 표면적들의 값을 구하면 됨

	1 <= H, W <= 100 height width
	1 <= Aij <= 100

	ex)
	1 1
	1
	1 x 1 x 1 -> 6 (정육면체)

	3 3
	1 3 4
	2 2 3
	1 2 4 -> 60

	밑면 3 x 3 = 9 (윗면도 동일)
	옆면1 3 + 3 + 3 + 2 = 11 (4는 가장 큰값, 맞은 편도 동일)
	옆면2 3 + 3 + 2 + 1 = 9
	-> 29 x 2 = 58인데 60이어야함 뭔가 문제 이해 실수 일 듯
	
	-> 풀이 보고 나랑 비슷한 해결 방안에 코드 구현해보면서 예제 맞는지 확인해볼꺼
	-> 문제를 이해하는데 오래걸렸는데 특히 옆면을 구할 때 
	왜 이전 면과 지금 면을 비교하여 그 차를 구하는지 이해가 안갔는데
	생각해보니 표면이라는게 구불구불 _-_-_ 이런것도 다 생각해야되는거였다.
	다시말해 123 12123 이게 다르다는 얘기이다. 이거를 생각 못하고 가장 큰 값 3만 생각해서
	계산해버려서 답이 자꾸 58이 나왔다는 거다. 
	막상 해결방안은 코드를 봐버려서 크게 수정할 것은 없지만 문제 이해를 먼저 제대로 못한
	부분이 너무 아쉽다. 풀이를 볼 때 코드를 볼 가능성이 크므로 항상 시간을 더 들여서
	고민해보다가 도전해볼 수 있도록 하자. 풀이 이해는 했다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int surfaceArea(vector<vector<int>> A)
{
	int area = 0;

	for (int i = 0; i < A.size(); i++) {
		int areaOfOneRow = A[i][0];
		
		for (int j = 0; j < A[i].size() - 1; j++) 
			areaOfOneRow += max(0, A[i][j + 1] - A[i][j]);
		
		area += areaOfOneRow * 2;
	}

	for (int i = 0; i < A[0].size(); i++) {
		int areaOfOneColumn = A[0][i];

		for (int j = 0; j < A.size() - 1; j++) 
			areaOfOneColumn += max(0, A[j + 1][i] - A[j][i]);
		
		area += areaOfOneColumn * 2;
	}

	area += A.size() * A[0].size() * 2;

	return area;
}

int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<int>> A(H);
	for (int i = 0; i < H; i++) {
		A[i].resize(W);
		
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
		}
	}

	int result = surfaceArea(A);
	cout << result << endl;
}

