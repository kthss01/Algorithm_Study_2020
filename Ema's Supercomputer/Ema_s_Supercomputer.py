# Ema's Supercomputer
'''
    n x m 사이즈의 grid가 있는데 각 cell은 good or bad로 되어있음
    여기서 valid plus를 찾아야 하며 
    가장 큰 2개의 plus의 곱을 구하는게 목표인데
    valid plus는 가운데를 기준으로 위아래좌우로 뻗고 길이가 같아야하며 길이가 홀수여야 함

    ex)
    xxx
    xox
    xxx

    xox
    ooo
    xox

    xxoxx
    xxoxx
    ooooo
    xxoxx
    xxoxx

    이런 식

    위에서는 2개 곱하면 5 x 9로 45임

    2 <= n <= 15
    2 <= m <= 15
'''

class Plus:
    def __init__(self, x, y, length):
        self.x = x
        self.y = y
        self.length = length

    def IsOverlap(self, other):
        x1, y1, x2, y2 = self.x, self.y, other.x, other.y
        len1, len2 = self.length, other.length

        if x1 == x2 and y1 + len1 >= y2 - len2 and y2 + len2 >= y1 - len1:
            return True
        if y1 == y2 and x1 + len1 >= x2 - len2 and x2 + len2 >= x1 - len1:
            return True
        if x2 >= x1 - len1 and x2 <= x1 + len1 and y1 >= y2 - len2 and y1 <= y2 + len2:
            return True
        if y2 >= y1 - len1 and y2 <= y1 + len1 and x1 >= x2 - len2 and x1 <= x2 + len2:
            return True

        return False

    def Area(self):
        return self.length*4 + 1

def IsValidPlus(x, y, length, n, m):
    if x - length < 0 or x + length >= n or y - length < 0 or y + length >= m:
        return False

    for i in range(x-length, x+length+1):
        if grid[i][y] == 'B':
            return False
    for j in range(y-length, y+length+1):
        if grid[x][j] == 'B':
            return False

    return True

def twoPluses(grid):
    n = len(grid)
    m = len(grid[0])

    plusList = []

    length = 0
    while length <= n or length <= m:
        for i in range(n):
            for j in range(m):
                if IsValidPlus(i, j, length, n, m):
                    plusList.append(Plus(i, j, length))
        length += 1

    areas = 0
    for i in range(len(plusList)):
        for j in range(len(plusList)):
            if i == j:
                continue

            if plusList[i].IsOverlap(plusList[j]) == False \
                and areas < plusList[i].Area() * plusList[j].Area():
                areas = plusList[i].Area() * plusList[j].Area()

    return areas

if __name__ == '__main__':
    nm = input().split()
    n = int(nm[0])
    m = int(nm[1])
    
    grid = []
    for _ in range(n):
        grid_item = input()
        grid.append(grid_item)

    result = twoPluses(grid)
    print(result)