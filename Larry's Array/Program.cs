// Larry's Array
/*
 * 자연수 1부터 시작하는 순열로 되어있는 배열이 있음
 * 규칙에 의해 회전을 시켜서 정렬이 가능한지 알아보기
 * 
 * 3개의 연속된 인덱스를 고르고 다음과 같은 방법으로 회전시킴
 * ABC -> BCA -> CAB -> ABC
 * 
 * ex)
 * A = {1,6,5,2,4,3}
 * [1,6,5,2,4,3] [6,5,2]
 * [1,5,2,6,4,3] [5,2,6]
 * [1,2,6,5,4,3] [5,4,3]
 * [1,2,3,5,6,4] [5,6,4]
 * [1,2,3,4,5,6]
 * => YES
 * 가능하면 YES 아니면 NO 출력
 * 
 * 1 <= t <= 10 test cases
 * 3 <= n <= 1000
 * 1 <= A[i] <= n
 */

 /*
  * 165243 [652]
  * 152643 [526]
  * 126543 [654]
  * 125463 [546]
  * 124653 [653]
  * 124536 [453]
  * 125346 [534]
  * 123456
  * 
  * 12354
  * 12543
  * 12435
  * 12354
  * 
  * 원리
  * n보다 n+1 or n+2 중 하나가 작아야함
  * n 다음 2개에 작은 값이 없으면 스탑 스탑 되었을 때 sort가 안되어있으면 실패
  * -> 그냥 반복문으로 돌리니 시간 초과남
  * 풀이 보니 15 tile problem가 있음
  * 
  * 공식
  * 각각의 수가 역이 될 갯수를 구함
  * ex)
  * 12 1 10 2 7 11 4 14 5 blank 9 15 8 13 6 3
  *     12는 11 inversions (이런 식)
  *     ...
  * grid 너비가 홀수면 inversion(역)의 수는 짝수여야 풀림
  * grid 너비가 짝수면 blank가 even row counting from bottom이면 역의 수는 홀수여야함
  * grid 너비가 짝수면 blank가 odd row counting from bottom이면 역의 수는 짝수여야함
  * 
  * -> ( (grid width odd) && (#inversions even) ) || 
  *     ( (grid width even) && ((blank on odd row from bottom)) == (#inversions even)) )
  *     
  * 이걸 이용하는데 blank의 위치는 항상 last block of grid라고 함
  * 따라서 여기서 규칙을 통합해서 inversion의 수가 짝수인지만 확인하면 됨
  */

using System;

namespace Larry_s_Array
{
    class Program
    {
        static string larryArray(int[] A)
        {
            // 시간 초과
            /*
            bool result = true;
            int[] B = new int[A.Length];
            B = (int[])A.Clone();

            Array.Sort(B);

            while (true)
            {
                bool bFind = false;

                for (int i=0; i<A.Length-2; i++)
                {
                    if (A[i] > A[i+1] || A[i] > A[i+2])
                    {
                        bFind = true;
                        int temp = A[i];
                        A[i] = A[i + 1];
                        A[i + 1] = A[i + 2];
                        A[i + 2] = temp;
                        break;
                    }
                }

                if (bFind == false) break;
            }

            for (int i=0; i<A.Length; i++)
            {
                if (A[i] != B[i])
                {
                    result = false;
                    break;
                }
            }

            return result == true ? "YES" : "NO";
            */

            int inversions = 0;

            for (int i=0; i<A.Length-1; i++)
            {
                for(int j=i+1; j<A.Length; j++)
                {
                    if (A[i] > A[j])
                        inversions++;
                }
            }

            return inversions % 2 == 0 ? "YES" : "NO";
        }

        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine());

                int[] A = Array.ConvertAll(Console.ReadLine().Split(' '),
                    ATemp => Convert.ToInt32(ATemp));

                string result = larryArray(A);
                Console.WriteLine(result);
            }
        }
    }
}
