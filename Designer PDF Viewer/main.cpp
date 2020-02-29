// Designer PDF Viewer
/*
	알파벳의 높이가 주어지고 letter가 주어질 때
	최대 높이 x 단어 수 (즉 영역) 구하기
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int designerPdfViewer(vector<int> h, string word) {
	int maxHeight = 0;

	for (char w : word) 
		maxHeight = max(maxHeight, h[w - 'a']);

	return maxHeight * word.length();
}

int main() {
	vector<int> heights(26);
	for (int i = 0; i < 26; i++)
		cin >> heights[i];
	string word;
	cin >> word;

	int result = designerPdfViewer(heights, word);
	cout << result << '\n';

	return 0;
}