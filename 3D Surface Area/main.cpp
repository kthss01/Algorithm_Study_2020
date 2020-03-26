// 3D Surface Area
/*
	3���� ������ �־����� ��
	ǥ������ �� ���ϱ�

	3���� ������ 2���� ���·� row col�� �� cell�� ���̷� �־���
	�׷��� �־����� �� ǥ�������� ���� ���ϸ� ��

	1 <= H, W <= 100 height width
	1 <= Aij <= 100

	ex)
	1 1
	1
	1 x 1 x 1 -> 6 (������ü)

	3 3
	1 3 4
	2 2 3
	1 2 4 -> 60

	�ظ� 3 x 3 = 9 (���鵵 ����)
	����1 3 + 3 + 3 + 2 = 11 (4�� ���� ū��, ���� �� ����)
	����2 3 + 3 + 2 + 1 = 9
	-> 29 x 2 = 58�ε� 60�̾���� ���� ���� ���� �Ǽ� �� ��
	
	-> Ǯ�� ���� ���� ����� �ذ� ��ȿ� �ڵ� �����غ��鼭 ���� �´��� Ȯ���غ���
	-> ������ �����ϴµ� �����ɷȴµ� Ư�� ������ ���� �� 
	�� ���� ��� ���� ���� ���Ͽ� �� ���� ���ϴ��� ���ذ� �Ȱ��µ�
	�����غ��� ǥ���̶�°� ���ұ��� _-_-_ �̷��͵� �� �����ؾߵǴ°ſ���.
	�ٽø��� 123 12123 �̰� �ٸ��ٴ� ����̴�. �̰Ÿ� ���� ���ϰ� ���� ū �� 3�� �����ؼ�
	����ع����� ���� �ڲ� 58�� ���Դٴ� �Ŵ�. 
	���� �ذ����� �ڵ带 �������� ũ�� ������ ���� ������ ���� ���ظ� ���� ����� ����
	�κ��� �ʹ� �ƽ���. Ǯ�̸� �� �� �ڵ带 �� ���ɼ��� ũ�Ƿ� �׻� �ð��� �� �鿩��
	����غ��ٰ� �����غ� �� �ֵ��� ����. Ǯ�� ���ش� �ߴ�.
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

