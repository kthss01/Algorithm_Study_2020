// Grading Students
/*
 * 모든 학생은 0 ~ 100 grade 받음
 * 40 이하는 failing grade
 * 
 * 점수가 5의 배수인 값과의 차가 3이하면 5의 배수로 반올림함
 * 단 점수가 38점보다 낮으면 그냥 유지
 * ex) 
 * 73 -> 75 (75 - 73 < 3)
 * 67 -> 67 (70 - 67 >= 3)
 * 38 -> 40 (40 - 38 < 3)
 * 33 -> 33 (33 < 38)
 * 
 * 1 <= n <= 60
 * 0 <= grades[i] <= 100
 * 
 */

using System;
using System.Collections.Generic;

namespace Grading_Students
{
    class Program
    {
        static List<int> Compute(List<int> grades)
        {
            for(int i=0; i<grades.Count; i++)
            {
                int num = (grades[i] / 5 + 1) * 5;
                if (grades[i] >= 38 && (Math.Abs(num - grades[i]) < 3))
                    grades[i] = num;
            }

            return grades;
        }

        static void Main(string[] args)
        {
            int gradesCount = Convert.ToInt32(Console.ReadLine().Trim());

            List<int> grades = new List<int>();
            for(int i=0; i<gradesCount; i++)
            {
                int gradesItem = Convert.ToInt32(Console.ReadLine().Trim());
                grades.Add(gradesItem);
            }

            List<int> result = Compute(grades);

            for(int i=0; i<gradesCount; i++)
            {
                Console.WriteLine(result[i]);
            }
        }
    }
}
