// Picking Numbers
/*
 * 배열이 주어질 때 
 * 두 수의 차이가 1이하인 수들의 하위 배열의 길이가 가장 긴 배열을 찾기
 * 
 * 0 <= n <= 100
 * 0 <= a[i] < 100
 * The answer will be >= 2
 * 
 */

using System;
using System.Collections.Generic;
using System.Linq;

namespace Picking_Numbers
{
    class Result
    {
        public static int pickingNumbers(List<int> a)
        {
            int maxCount = 0;

            HashSet<int> set = a.ToHashSet();
            foreach (int i in set)
            {
                var temp = from ele in a
                           where ele - i <= 1 && ele - i >= 0
                           select ele;
                int count = temp.Count();
                maxCount = Math.Max(count, maxCount);
            }

            return maxCount;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine().Trim());

            List<int> a = Console.ReadLine().TrimEnd().Split(' ').ToList()
                .Select(aTemp => Convert.ToInt32(aTemp)).ToList();

            int result = Result.pickingNumbers(a);

            Console.WriteLine(result);
        }
    }
}
