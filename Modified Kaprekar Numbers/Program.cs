// Modified Kaprekar Numbers
/*
 * square 제곱
 * 
 * 카프리카 수
 * 인도의 수학자인 D.F 카프리카가 발견한 숫자로, 회생숫자라고 부름
 * 어떤수의 제곱수를 두 부분으로 나누어 더하였을 때 다시 원래의 수가 되는 수들을 의미
 * ex)
 * 45 
 * 45^2 = 2025 (20+25 = 45)
 * 
 * 문제에서는 수정된 카프리카 수로
 * 양수 n과 자릿수 d가 주어지면
 * n의 제곱은 2 x d 자리수나 (2 x d) -1 자리수가 됨
 * 제곱된 수를 l과 r로 나누고 r을 d 자리수만크믕로 l을 나머지로 하여 
 * 카프리카 수 n이 됨
 * 
 * 두 양수 p, q가 주어질 때 (p < q)
 * p, q가 포함된 범위내에 카프리카 수 구하기
 * 
 * 0 < p < q < 100000
 * 만약 범위 내에 없으면 INVALID RANGE 출력
 * 
 * ex)
 * n = 5 d = 1
 * n^2 = 25
 * 2, 5 2+5 = 7 != 5
 * 
 * n = 9 d = 1
 * n^2 = 81
 * 1+8 = 9 n
 */

using System;
using System.Collections.Generic;

namespace Modified_Kaprekar_Numbers
{
    class Program
    {
        static void kaprekarNumbers(int p, int q)
        {
            List<int> result = new List<int>();

            for (int i = p; i<= q; i++)
            {
                long n = (long)i * (long)i;
                int d = i.ToString().Length;
                string nStr = n.ToString();

                long l;
                if (nStr.Length == 1)
                    l = 0;
                else
                    l = Convert.ToInt64(nStr.Substring(0, nStr.Length - d));
                long r = Convert.ToInt64(nStr.Substring(nStr.Length - d));

                if (l + r == i)
                    result.Add(i);
            }

            if (result.Count == 0)
                Console.WriteLine("INVALID RANGE");
            else
            {
                foreach (int ele in result)
                    Console.Write(ele + " ");
            }
        }

        static void Main(string[] args)
        {
            int p = Convert.ToInt32(Console.ReadLine());
            int q = Convert.ToInt32(Console.ReadLine());

            kaprekarNumbers(p, q);
        }
    }
}
