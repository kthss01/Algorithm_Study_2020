# Manasa and Stones
'''
    A is out on a hike - 하이킹 중이다.
    a trail of stones 돌의 흔적

    규칙에 맞게 가능한 경우의 수 모두 구하는 거임
    n과 a, b가 주어지는데
    n은 반복 횟수 
    a, b 가능한 차이 임
    0부터 시작해서 n번까지 연속적인 다음의 수와의 차이가 a or b로 나올 수 있는 모든 경우를 구하는 거

    ex)
    n = 2
    a = 2 b = 3
    2나 3차이로 2번째까지 나올 경우 구하기
    0 2 4
    0 2 5
    0 3 5
    0 3 6
    -> 4,5,6 가능

    1 <= T <= 10
    1 <= n,a,b <= 10^3
'''

def stones(n,a,b):
    result = []
    n -= 1

    for itr in range(0, n+1):
        num = a*(n-itr) + b*(itr)
        result.append(num)
    result = list(set(result))
    result.sort()

    return result

if __name__ == '__main__':
    T = int(input())

    for T_itr in range(T):
        n = int(input())
        a = int(input())
        b = int(input())

        result = stones(n,a,b)

        print(' '.join(map(str, result)))