
# Diagonal Difference
"""
    nxn matrix를 받아 각 대각선의 합에 차를 구하기

    1 2 3
    4 5 6
    9 8 9

    1+5+9 = 15
    3+5+9 = 17

    |15-17| = 2

    n
    -100 <= arr[i][j] <= 100
"""

n = int(input())
arr = list()

for _ in range(n):
    arr.append(list(map(int, input().split())))

a = b = 0
for i in range(n):
    a += arr[i][i]
    b += arr[n-i-1][i]

print(abs(a-b))
