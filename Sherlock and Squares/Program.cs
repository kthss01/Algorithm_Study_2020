// Sherlock and Squares
/* 
 * squares 사각형
 * square integer 제곱수 ex) 1,4,9,16,25
 * 
 * 숫자 범위가 주어질 때 제곱수의 갯수 구하기
 * 
 * 1 <= q <= 100 query
 * 1 <= a <= b <= 10^9
 */

using System;
using System.Collections.Generic;

namespace Sherlock_and_Squares
{
    class Program
    {
        static List<int> s;

        static int squares(int a, int b)
        {
            // 시간 초과남
            //int cnt = 0;
            //
            //for (int s = a; s <= b; s++)
            //{
            //    int t = (int)Math.Ceiling(Math.Sqrt(s));
            //    if (t * t == s)
            //        cnt++;
            //}
            //
            //return cnt;

            //if (s == null)
            //{
            //    s = new List<int>();
            //    for (int i = 1; i * i < 1000000000; i++)
            //        s.Add(i * i);
            //}
            //
            //var t = s.FindAll(x => x >= a && x <= b);
            //
            //return t.Count;

            // 더 쉬운 방법도 있음
            return (int)Math.Floor(Math.Sqrt(b)) - (int)Math.Ceiling(Math.Sqrt(a)) + 1;
        }

        static void Main(string[] args)
        {
            int q = Convert.ToInt32(Console.ReadLine());

            for(int qItr = 0; qItr < q; qItr++)
            {
                string[] ab = Console.ReadLine().Split(' ');

                int a = Convert.ToInt32(ab[0]);
                int b = Convert.ToInt32(ab[1]);
                
                int result = squares(a, b);
                Console.WriteLine(result);
            }
        }
    }
}
