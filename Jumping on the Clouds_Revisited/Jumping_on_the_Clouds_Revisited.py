# Jumping on the Clouds: Revisited
'''
    thunderheads clouds 뇌우 구름
    cumulus clouds 적운 구름

    배열이 주어지고 배열을 순환하면서 점프하다 원점으로 돌아오는데
    100 에너지에서 시작해서 에너지가 얼마나 남는지 알아보기
    한번 점프마다 1씩 떨어지고 배열값이 1인 (천둥번개) 곳에 도달하면 추가로 2가 더 떨어짐

    ex)
    c = [0,0,1,0] k = 2
    0 -> 2 -> 0 => -2
    c[2] == 1 이므로 -> -2 
    따라서 100-4 = 96

    2 <= n <= 25 (배열)
    1 <= k <= n (점프)
    n % k == 0
    c[i] == 0 or 1
'''

def jumpingOnClouds(c, k):
    e = 100
    p = 0

    while True:
        p = (p + k) % len(c)
        e -= 1
        if c[p] == 1:
            e -= 2
        if p == 0:
            break

    return e

if __name__ == '__main__':
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])
    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c,k)
    print(result)
