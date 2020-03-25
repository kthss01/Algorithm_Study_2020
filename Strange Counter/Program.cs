// Strange Counter
/*
 * 규칙
 * 처음엔 3으로 시작
 * 1씩 내려가다 1이되면 리셋되며
 * 리셋될 때 이전 사이클의 처음 값의 x 2
 * 
 * ex)
 * 3 2 1
 * 6 5 4 3 2 1
 * 12 11 10 9 8 7 6 5 4 3 2 1 ....
 * 
 * t가 주어질 때 값 구하기
 * 
 * 1 <= t <= 10^12
 */

 /*
  * 그냥 반복문 돌리면 시간초과
  * 
  * 식
  * t = 1,4,10,22,46 이렇게 간다 치면
  * m = 0, 1, 2, ...
  * 
  * 3x2^m - 2 = t
  * -> 이걸 다시 m에 대해 풀면
  * m = log2((t+2)/3)
  * m = (int)log2((t+2)/3)
  * 
  * v = 3, 6, 12, 24
  * v = 3x2^m (m = 0,1,2...)
  * 
  * 정답은 v - (t - (3x2^m - 2)) <- 차이빼는거
  */

using System;

namespace Strange_Counter
{
    class Program
    {
        static long strangeCounter(long t)
        {
            //long p = 3;
            //long nextT = 1;
            //
            //while (true)
            //{
            //    nextT += p;
            //    if (t < nextT)
            //    {
            //        nextT -= p;
            //        break;
            //    }
            //    p *= 2;
            //}
            //
            //for (int i = 0; i < t - nextT; i++)
            //    p--;
            //
            //return p;

            // 이런 방법도 있음
            long rem = 3;
            while (t > rem) 
            {
                t = t - rem;
                rem *= 2;
            }
            return rem - t + 1;

            // 내가 식 만든 거
            long m = (long)Math.Log2((t + 2) / 3);
            long v = 3 * (long)Math.Pow(2, m);

            return v - (t - (3 * (long)Math.Pow(2, m) - 2));
        }

        static void Main(string[] args)
        {
            long t = Convert.ToInt64(Console.ReadLine());

            long result = strangeCounter(t);
            Console.WriteLine(result);
        }
    }
}
