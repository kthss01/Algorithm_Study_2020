# Organizing Containers of Balls
'''
    컨테이너에 종류가 다른 볼들이 섞여있는데
    같은 종류의 볼들만 컨테이너에만 담아 분류할 수 있게
    볼들을 swap하려고 함 swap을 통해 분류가 가능한지 구하기

    1 <= q <= 10 query
    1 <= n <= 100 컨테이너 갯수
    0 <= M[container][type] <= 10^9

    가능하면 Possible 아니면 Impossible 출력
'''

"""
    생각한 해결방안
    볼들의 총 갯수가 짝수여야 스왑이 가능해서 가능하다
    -> 짝수인데 아닌 경우가 있는지 -> 없는 거 같음
    -> 예제가 안됨

    -> 해결 못해 풀이 봄
    풀이 정리
    각각의 컨테이너에 볼들은 결국 같은 타입이 들어가게 될것임 (+1 -1 해도 수는 유지되니까)
    따라서 각 컨테이너에 얼마만큼 볼이 들어있는지 확인 후
    각 타입의 볼들의 갯수와 같은지 확인하면 되는 거

    identical 같은
    intact 손대지 않은
"""

def organizingContainers(container):
    balls = []
    types = []
    n = len(container)

    for i in range(n):
        ball = type = 0
        for j in range(n):
            ball += container[i][j]
            type += container[j][i]
        balls.append(ball)
        types.append(type)

    balls.sort()
    types.sort()

    for i in range(n):
        if balls[i] != types[i]:
            return "Impossible"
    return "Possible"

if __name__ == '__main__':
    q = int(input())

    for q_itr in range(q):
        n = int(input())

        container = []

        for _ in range(n):
            container.append(list(map(int, input().rstrip().split())))

        result = organizingContainers(container)

        print(result)