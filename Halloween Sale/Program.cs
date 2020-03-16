// Halloween Sale
/*
 * 세일을 하는데 p, d, m 규칙을 가짐
 * p로 살 수 있고 그 다음부터는 d 할인 해주고 m 가격부턴 그 가격으로 살 수 있게됨
 * ex) p=20, d=3, m=6
 * 20,17,14,11,6,6,6,6,6
 * 
 * s만큼 있을 때 얼마나 살 수 있을지 구하기
 * 
 * 1 <= m <= p <= 100
 * 1 <= d <= 100
 * 1 <= s <= 10^4
 */

using System;

namespace Halloween_Sale
{
    class Program
    {
        static int howManyGames(int p, int d, int m, int s)
        {
            int c = p;
            int cnt = 0;

            while(s >= c)
            {
                cnt++;
                s -= c;
                if (c > m)
                    c -= d;
                if (c < m)
                    c = m;
            }

            return cnt;
        }

        static void Main(string[] args)
        {
            int[] pdms = Array.ConvertAll(Console.ReadLine().Split(' '),
                arrTemp => Convert.ToInt32(arrTemp));
            int p = pdms[0], d = pdms[1], m = pdms[2], s = pdms[3];

            int result = howManyGames(p, d, m, s);
            Console.WriteLine(result);
        }
    }
}
