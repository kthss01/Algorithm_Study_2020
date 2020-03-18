# Chocolate Feast 
'''
    feast 잔치
    wrappers 포장지

    초콜릿을 사먹는데 포장지를 2개 반납하면 초콜릿을 1개 줌
    총 초콜릿을 몇개 먹는지 구하기
    
    ex)
    n = 15
    cost = 3
    m = 2 (포장지 몇 개 반납시 초콜릿 주는지)

    초콜릿 5 포장지 5
    -> 4 반납 2 초콜릿 나머지 1
    초콜릿 2 포장지 3
    -> 2 반납 1 초콜릿 나머지 1
    초콜릿 1 포장지 2
    -> 2 반납 1 초콜릿 나머지 0
    초콜릿 1 포장지 1
    => 5 + 2 + 1 + 1 = 9

    1 <= t <= 1000 test cases
    2 <= n <= 10^5
    1 <= c <= n
    2 <= m <= n
'''

def chocolateFeast(n, c, m):
    chocolate = int(n / c)
    wrappers = chocolate

    while wrappers >= m:
        temp = int(wrappers / m)
        wrappers %= m
        chocolate += temp
        wrappers += temp

    return chocolate

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        ncm = input().split()
        n = int(ncm[0])
        c = int(ncm[1])
        m = int(ncm[2])

        result = chocolateFeast(n, c, m)

        print(result)
