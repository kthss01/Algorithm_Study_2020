# Save the Prisoner!
"""
   의자에 죄수를 앉히고 캔디를 순서대로 나눠주는데
   마지막 캔디를 받는 죄수가 누구인지 구하기

   죄수와 캔디의 갯수가 주어지고 시작 번호가 주어짐
   ex)
   4 6 2
   -> 2 3 4 1 2 3 -> 3번이 마지막임

   1 <= t <= 100 test cases
   1 <= n <= 10^9 죄수
   1 <= m <= 10^9 캔디
   1 <= s <= n 시작번호
"""

def saveThePrisoner(n, m, s):
    result = s + (m % n) - 1
    if result > n:
        result = result % n
    elif result == 0:
        result = n
    return result

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        nms = input().split()
        n = int(nms[0])
        m = int(nms[1])
        s = int(nms[2])

        result = saveThePrisoner(n,m,s)

        print(result)