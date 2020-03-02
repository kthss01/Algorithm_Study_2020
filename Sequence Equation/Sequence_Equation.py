# Sequence Equation
'''
    배열을 규칙을 가지고 새로 만듬
    규칙
    정수 n, p(1), p(2), ... , p(n)
    각각의 요소는 1 <= p(x) <= n 만족
    x 1 <= x <= n
    p(p(y)) = x 인 y 구하는거
    
    ex)
    p = [5,2,1,3,4]
    x = 1 ~ 5
    
    x = 1 == p[3], p[4] = 3 -> p[p[4]] = 1
    x = 2 == p[2], p[2] = 2 -> p[p[2]] = 2
    x = 3 == p[4], p[5] = 4 -> p[p[5]] = 3
'''

def permutationEquation(p):
    y = []
    for x in range(1,len(p) + 1):
        y.append(p.index(p.index(x) + 1) + 1)
    return y

if __name__ == '__main__':
    n = int(input())
    p = list(map(int, input().rstrip().split()))

    result = permutationEquation(p)
    print('\n'.join(map(str,result)))