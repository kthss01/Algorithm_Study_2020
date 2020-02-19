using System;

namespace C____Study
{
    class Study
    {
        public void Output()
        {
            // format 출력
            int a = 10;
            Console.WriteLine("a = {0}", a);

            // 소수점 자리수 
            /*
             * .ToString("F") 2자리
             * .ToString("F0") 0자리
             * .ToString("F1") 1자리
             * 
             * N은 3자리마다 콤마가 표시됨
             * d.ToString("N") // 1,054.32
             * d.ToString("N0") // 1,054
             * d.ToString("N1") // 1,054.3
             * d.ToString("N2") // 1,054.32
             */
            double d = 1054.32179;

            Console.WriteLine(d.ToString("F"));
            Console.WriteLine(d.ToString("F0"));
            Console.WriteLine(d.ToString("F1"));
            Console.WriteLine(d.ToString("F2"));
            Console.WriteLine(d.ToString("F3"));

            Console.WriteLine(d.ToString("N"));
            Console.WriteLine(d.ToString("N0"));
            Console.WriteLine(d.ToString("N1"));
            Console.WriteLine(d.ToString("N2"));
            Console.WriteLine(d.ToString("N3"));
        }

        public void Input()
        {
            // 입력 받기
            /*
             * Console.ReadLine() // string으로 입력받음
             */

            // 자료형 변환
            /*
             * string으로 입력받으므로 .Parse() 나 Convert.To~~~() 이용
             */

            int input;
            Console.Write("숫자를 입력하세요: ");

            //input = int.Parse(Console.ReadLine());

            string strInput;
            strInput = Console.ReadLine();
            input = Convert.ToInt32(strInput);

            Console.WriteLine("입력한 숫자는 " + input);
        }

        public void MultiInput()
        {
            // 여러 수 입력받기
            /*
             * string으로 받아서 split으로 잘라서 씀
             */

            int n;
            n = int.Parse(Console.ReadLine());

            //int[] arr = new int[n];
            //string str;
            //string[] token;
            //str = Console.ReadLine();
            //{
            //    token = str.Split(' ');
            //    for(int i = 0; i < token.Length; i++)
            //    {
            //        token[i].Trim();
            //        arr[i] = Convert.ToInt32(token[i]);
            //    }
            //}

            // 더 쉬운 방법
            int[] arr = Array.ConvertAll(
                Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));

            for (int i = 0; i < n; i++) 
                Console.Write("[{0}] ", arr[i]);
            Console.WriteLine();
        } 
    }

    class Program
    {
        static void Main(string[] args)
        {
            Study study = new Study();

            // 출력 예제
            //study.Output();

            //  입력받기 예제
            //study.Input();

            // 여러 수 입력받기 예제
            study.MultiInput();
        }
    }
}
