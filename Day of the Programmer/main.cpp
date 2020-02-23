// Day of the Programmer
/*
	Day of the Programmer (1년의 256번째날)
	1700 ~ 1917 Julian calndar
	1919 이후 Gregorian calendar
	1918 옮겨가는 시점
	1월 31일 다음 2월 14일

	2월이 변수
	Julian calendar leap years are divisible by 4
	Gregorian calendar leap years
	Divisible by 400
	Divisible by 4 and not divisible by 100

	year이 주어질때 256th day 찾기
	print dd.mm.yyyy

	ex)
	year = 1984
	1984 % 4 == 0 a leap year
	256th day -> September 12
	-> 12.09.1984

	1700 <= y <= 2700
*/

/*
	leap year이면 12.09.yyyy
	아니면 13.09.yyyy

	1918의 경우 leap x
	14일 빼야함 2월 14일부터 시작이니 -> 더 해야하는 거임
	29.08.1918 -> 26.09.1918
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int y;
	cin >> y;

	if (y == 1918)
		cout << "26.09.1918\n";
	else {
		bool bCheck = y > 1918;
		bool bLeap;

		// Gregorian
		if (bCheck) 
			bLeap = y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
		// Julian
		else 
			bLeap = y % 4 == 0;
		
		if (bLeap)
			cout << "12.09." << y << '\n';
		else
			cout << "13.09." << y << '\n';
	}

	return 0;
}