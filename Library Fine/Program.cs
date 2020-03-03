// Library Fine
/*
 * 책 연체료 계산하기
 * 
 * 일수로 연체되면 일 x 15
 * 달수로 연체되면 달 x 500
 * 년수로 연체되면 고정 10000
 * 
 * 1월 1일까지든 12월 31일까지든 다음해 1일에 반납하면 무조건 년수 연체
 * 
 * 1 <= d1,d2 <= 31
 * 1 <= m1,m2 <= 12
 * 1 <= y1,y2 <= 3000
 * 그레고리안 달력 날짜임 보증됨
 */

using System;

namespace Library_Fine
{
    class Program
    {
        static int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2)
        {
            if (y1 > y2) return 10000;
            if (y1 == y2 && m1 > m2) return 500 * (m1 - m2);
            if (y1 == y2 && m1 == m2 && d1 > d2) return 15 * (d1 - d2);

            return 0;
        }

        static void Main(string[] args)
        {
            string[] d1M1Y1 = Console.ReadLine().Split(' ');
            int d1 = Convert.ToInt32(d1M1Y1[0]);
            int m1 = Convert.ToInt32(d1M1Y1[1]);
            int y1 = Convert.ToInt32(d1M1Y1[2]);

            string[] d2M2Y2 = Console.ReadLine().Split(' ');
            int d2 = Convert.ToInt32(d2M2Y2[0]);
            int m2 = Convert.ToInt32(d2M2Y2[1]);
            int y2 = Convert.ToInt32(d2M2Y2[2]);

            int result = libraryFine(d1, m1, y1, d2, m2, y2);
            Console.WriteLine(result);
        }
    }
}
