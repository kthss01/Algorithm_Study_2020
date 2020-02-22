// Migratory Birds
/*
 * 새가 이주하는걸 배열로 표현하고
 * 타입마다 번호로 표시함
 * 어떤 타입이 가장 많이 알아내기
 * 빈도가 같으면 낮은 번호 출력
 * 
 * 5 <= n <= 2 x 10^5
 * 1,2,3,4,5 중 하나 보증
 * 
 * 가장 빈도가 많은 타입 출력, 같으면 낮은 번호
 */

/*
 * migratory 철새, 이주하는
 * continent 대륙
 * spotted 더럽혀진
 */

using System;
using System.Collections.Generic;
using System.Linq;

namespace Migratory_Birds
{
    class Program
    {
        static int migratoryBirds(List<int> arr)
        {
            int[] type = new int[5];

            foreach (int ele in arr)
            {
                type[ele-1]++;
            }

            int max = 0;
            int commonType = 0;
            for(int i = 0; i < 5; i++)
            {
                if (max < type[i])
                {
                    max = type[i];
                    commonType = i + 1;
                }
            }

            return commonType;
        }

        static void Main(string[] args)
        {
            int arrCount = Convert.ToInt32(Console.ReadLine());
            List<int> arr = Console.ReadLine().TrimEnd().Split(' ')
                .ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();

            int result = migratoryBirds(arr);
            Console.WriteLine(result);
        }
    }
}
