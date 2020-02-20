# Between Two Sets
"""
    factor = 인수 ex) 6 = 2 x 3에서 2와 3을 6의 인수 factorization : 인수분해

    두 배열이 있는데 조건에 맞는 정수 모두 구하기
    조건
    첫번째 배열에 요소들은 조건에 맞는 정수의 인수
    조건에 맞는 정수는 두번째 배열의 요소들의 인수임

    ex)
    a = [2,6], b = [24,36]
    -> 6, 12
    6은 2,6을 인수로 가지고 있음
    24,36은 6을 인수로 가지고 있음
    12는 2,6은 인수로 가지고 잇음
    24,36은 12를 인수로 가지고 있음

    1 <= n,m <= 10
    1 <= a[i] <= 100
    1 <= b[j] <= 100

    정수 갯수 출력
"""

"""
    해결방안1 -> 방향 잘못잡음 수가 여러개라 최대공약수 구하기 힘듬
    두번째 배열의 gcd(최대공약수) 구하고 최대공약수의 인수들을 구함
    ex) a = [2,6], b = [24,36]
    b -> 12 -> 1,2,3,4,6,12
    해당 인수들이 첫번째 배열의 요소들을 모두 인수로 갖고 있는지 확인
    -> 나머지값이 0인지 확인

    해결방안2 
    두번째 배열의 공약수를 구한다 for문으로 1부터 쭉 돌아봄
    해당 공약수가 첫번째 배열의 값을 약수로 갖을 수 있는지 체크하기

"""

"""
def gcd(a, b):
    if a < b:
        a, b = b, a

    while b != 0:
        r = a % b
        a = b
        b = r

    return a
"""

def getTotalX(arr, brr):

    brr.sort()

    # 두번째 배열의 공약수 구하기
    factors = []

    for i in range(1, brr[-1]+1): # 두번째 배열의 가장 큰 값까지 반복
        isFactor = True
        for b in brr:
            if b % i != 0:
                isFactor = False
                break
        if isFactor == True:
            factors.append(i)

    ans = 0
    # 해당 공약수가 첫번째 배열의 수를 모두 약수로 갖는지 확인
    for factor in factors:
        isAnswer = True
        for a in arr:
            if factor % a != 0:
                isAnswer = False
                break
        if isAnswer == True:
            ans += 1

    return ans

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])
    m = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))
    brr = list(map(int, input().rstrip().split()))

    total = getTotalX(arr, brr)
    print(total)
