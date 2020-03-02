# Circular Array Rotation
"""
    배열을 right circular rotation한 뒤의 배열의 인덱스로 값 구하기

    ex)
    a = [3,4,5] k = 2
    2번 로테이션
    -> [3,4,5] -> [5,3,4] -> [4,5,3]
    m = [1,2]
    a[1] = 5
    a[2] = 3

    n, k, q (1 <= n <= 10^5(배열), 1 <= k <= 10^5(회전수), 1 <= q <= 500 (쿼리))
    1 <= a[i] <= 10^5
    0 <= m < n (배열의 인덱스)
"""

def circularArrayRotation(a, k, queries):
    n = k % len(a)

    for _ in range(n):
        a.insert(0, a.pop())

    r = []
    for q in queries:
        r.append(a[q])

    return r

if __name__ == '__main__':
    nkq = input().split()
    n = int(nkq[0])
    k = int(nkq[1])
    q = int(nkq[2])
    a = list(map(int, input().rstrip().split()))

    queries = []

    for _ in range(q):
        queries_item = int(input())
        queries.append(queries_item)

    result = circularArrayRotation(a,k,queries)

    print('\n'.join(map(str,result)))