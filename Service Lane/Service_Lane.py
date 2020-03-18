# Service Lane
'''
   lane 레인 

   도로 옆에 엔진 이상으로 정차 시킬 수 있는 서비스 레인이 있음
   거기의 넓이로 이루어진 배열이 주어질 때 
   시작과 끝 구간이 주어질 때 서비스 레인에 들어갈 수있는 최대 차의 사이즈 구하기

   2 <= n <= 1000000 서비스 레인 넓이
   1 <= t <= 1000 test cases 
   0 <= i < j < n
   2 <= j - i + 1 <= min(n, 1000)
   1 <= width[k] <= 3, where 0 <= k < n
'''

def serviceLane(n, cases):
    result = []

    for i,j in cases:
        result.append(min(width[i:j+1]))

    return result

if __name__ == '__main__':
    nt = input().split()
    n = int(nt[0])
    t = int(nt[1])

    width = list(map(int, input().rstrip().split()))

    cases = []

    for _ in range(t):
        cases.append(list(map(int, input().rstrip().split())))
    
    result = serviceLane(width, cases)

    print('\n'.join(map(str, result)))

