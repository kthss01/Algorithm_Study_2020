
# Drawing Book
"""
   책에 페이지를 최소한의 수로 넘기는 방법 찾기
   
   시작이나 끝부터 시작 가능하고
   1page는 오른쪽 페이지부터 시작함
   그다음은 마지막 페이지말고는 항상 양 페이지에 있음

   페이지 수랑 찾고자하는 페이지가 잇을 때 최소한의 수로 넘기는 방법 찾기

   1 <= n <= 10^5
   1 <= p <= n

   ex)
   6 총 6페이지
   2 찾고자하는 페이지 
   처음부터 시작 |1 -> 2|3 = 1번
   끝부터 시작 6| -> 4|5 -> 3|4 = 2번
   정답 1번

   5
   4
   |1 -> 2|3 -> 4|5 = 2
   4|5 = 0
   -> 0
"""

def pageCount(n, p):
    start = end = 0

    if n % 2 == 0: # 짝수면 마지막페이지 왼쪽
        book = [0, 1, n, n+1]
    else: # 홀수면 오른쪽
        book = [0, 1, n-1, n]

    while(True):
        # 페이지 찾기 검사
        if book.count(p) >= 1:
            break
        start += 1
        end += 1
        book[0] += 2
        book[1] += 2
        book[2] -= 2
        book[3] -= 2

    if start < end:
        return start
    else:
        return end

if __name__ == '__main__':
    n = int(input())
    p = int(input())

    result = pageCount(n,p)
    print(result)