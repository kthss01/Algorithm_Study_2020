# Jumping on the Clouds
'''
    cumulus 적운
    thunderheads cloud 뇌우 구름

    0 1 로 이루어진 배열이 있고 1을 피해서 끝까지 도달해야함
    한번에 점프를 할 수 있는데 1, 2 점프 가능
    최대한 적게 점프해서 가는 방법 구하기

    ex)
    0 1 0 0 0 1 0
    0 -> 2 -> 4 -> 6 = 3 jump

    2 <= n <= 100
    c[i] {0, 1}
    c[0] = c[n-1] = 0 항상 가능한 경우만 있음
'''

def jumpingOnClouds(c):
    index = 0
    jump = 0

    while index != len(c) - 1:
        if index + 2 < len(c) and c[index + 2] != 1:
            index += 2
        else:
            index += 1
        jump += 1

    return jump

if __name__ == '__main__':
    n = int(input())
    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)
    print(result)