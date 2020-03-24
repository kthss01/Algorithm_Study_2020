# Cavity Map
'''
    cavity 공동
    strictly 엄밀히

    if and only if (줄여서 iff)
    a iff b 필요충분조건이라는 거
    b if a (a -> b)
    a only if b (a <- b)

    사각형 맵이 있고 그 매트릭스는 정수로 표현된 깊이로 이루어져있음
    거기엔 cavity라는게 있는데 이걸 찾아야함
    이 주변은 이곳보다 깊이가 낮고 이 것은 경계에 존재하지는 않음

    cavity를 X로 표현해서 다시 출력하기

    ex)
    989
    191
    111

    989
    1X1
    111

    X 주변 [8,1,1,1]로 9보다 작고 경계에 있지 않음

    1 <= n <= 100
'''

def cavityMap(grid):
    n = len(grid) 
   
    for row in range(n):
        if row == 0 or row == n - 1:
            continue
        for col in range(n):
            if col == 0 or col == n - 1:
                continue
            cell = grid[row][col]
            # \ 나 ()쓰면 여러 줄에 나눠서 쓸 수 있음
            if (cell > grid[row-1][col] and 
                cell > grid[row][col-1] and 
                cell > grid[row+1][col] and 
                cell > grid[row][col+1]):
                grid[row] = grid[row][:col] + 'X' + grid[row][col+1:]

    return grid

if __name__ == '__main__':
    n = int(input())

    grid = []

    for _ in range(n):
        grid_item = input()
        grid.append(grid_item)

    result = cavityMap(grid)

    print('\n'.join(result))

