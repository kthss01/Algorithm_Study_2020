// Kangaroo
/*
 * 캥거루 2마리 있음
 * 캥거루1 -> x1 jump per v1
 * 캥거루2 -> x2 jump per v2
 * 
 * 점프했을 때 같은 시간에 같은 위치에 있는지 알아보기
 * 
 * ex)
 * x1 = 2 v1 = 1
 * x2 = 1 v2 = 2
 * -> x = 3 (x1 + v1 = 2 + 1) (x2 + v2 = 1 + 3) -> YES
 * 
 * 3x + 0
 * 2x + 4
 * 
 * 2x + 0
 * 3x + 5
 * 
 * aX + b = cX + d
 * (a-c)X = (d-b)
 * X = (d-b) / (a-c) // > 0 이어야함
 * a=v1 b=x1 c=v2 d=x2
 * (x2-x1)/(v1-v2)
 * 
 * 0 <= x1 < x2 <= 10000
 * 1 <= v1 <= 10000
 * 1 <= v2 <= 10000
 * 
 * 같은 시간 같은 위치면 YES
 * 아니면 NO
 * 
 */

 /*
  * choreographing 안무
  */

using System;

namespace Kangaroo
{
    class Program
    {
        static string kangaroo(int x1, int v1, int x2, int v2)
        {
            bool isSame = true;

            if (v1 == v2 && x1 != x2) // 평행
                isSame = false;
            else if (v1 != v2)
            {
                double x = (double)(x2 - x1) / (double)(v1 - v2);
                if (x < 0) // x값이 0보다 이전에 만남
                    isSame = false;
                if (x != (int)x) // 정수 x가 아닐 때
                    isSame = false;
            }
           
            return isSame ? "YES" : "NO";
        }

        static void Main(string[] args)
        {
            string[] x1v1x2v2 = Console.ReadLine().Split(' ');
            int x1 = Convert.ToInt32(x1v1x2v2[0]);
            int v1 = Convert.ToInt32(x1v1x2v2[1]);
            int x2 = Convert.ToInt32(x1v1x2v2[2]);
            int v2 = Convert.ToInt32(x1v1x2v2[3]);

            string result = kangaroo(x1, v1, x2, v2);

            Console.WriteLine(result);
        }
    }
}
