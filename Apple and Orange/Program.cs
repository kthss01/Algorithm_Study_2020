// Apple and Orange
/*
 * 사과 나무 오렌지 나무가 있고 가운데 집이 있음
 * 집 크기는 s ~ t 이고
 * 왼쪽에 사과나무 a 오른쪽에 오렌지나무 b
 * d 는 나무 기준 과일 떨어진 위치 왼쪽이 - 오른쪽이 +
 * 
 * d와 m 사과, n 오렌지가 주어졌을 때 
 * 집쪽에 얼마나 많은 사과와 오렌지가 떨어졌는지 계산하기
 * 
 * ex) 
 * s = 7 t = 10
 * a = 4, apples = [2,3,-4] -> [6,7,0]
 * b = 12, oranges = [3,-2,-4] -> [15,10,8]
 * -> 7 ~ 10 -> 1 , 2
 * 
 * 1 <= s,t,a,b,m,n <= 10^5
 * -10^5 <= d <= 10^5
 * a < s < t < b
 */

 /*
  * abundance 풍부
  */

using System;

namespace Apple_and_Orange
{
    class Program
    {
        static void Compute(int s, int t, int a, int b, int[] apples, int[] oranges)
        {
            int appleCount = 0, orangeCount = 0;

            foreach(int apple in apples)
            {
                int apple2 = apple + a;
                if (apple2 >= s && apple2 <= t)
                    appleCount++;
            }

            foreach (int orange in oranges)
            {
                int orange2 = orange + b;
                if (orange2 >= s && orange2 <= t)
                    orangeCount++;
            }

            Console.WriteLine(appleCount);
            Console.WriteLine(orangeCount);
        }

        static void Main(string[] args)
        {
            string[] st = Console.ReadLine().Split(' ');
            int s = Int32.Parse(st[0]);
            int t = Int32.Parse(st[1]);

            string[] ab = Console.ReadLine().Split(' ');
            int a = Int32.Parse(ab[0]);
            int b = Int32.Parse(ab[1]);

            string[] mn = Console.ReadLine().Split(' ');
            int m = Int32.Parse(mn[0]);
            int n = Int32.Parse(mn[1]);

            int[] apples = Array.ConvertAll(
                Console.ReadLine().Split(' '), applesTemp => Convert.ToInt32(applesTemp));
            int[] oranges = Array.ConvertAll(
                Console.ReadLine().Split(' '), orangesTemp => Convert.ToInt32(orangesTemp));

            Compute(s, t, a, b, apples, oranges);
        }
    }
}
