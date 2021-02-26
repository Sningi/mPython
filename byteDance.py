def getMin(arr):
    rowLen = len(arr[0])
    colLen = len(arr)
    min = 0
    for row in range(rowLen):
        for col in range(colLen):
            if arr[row][col] == 2:
                # min += processOne(arr, row, col, rowLen, colLen)
                change = 0
                if row - 1 >= 0 and arr[row - 1][col] == 1:
                    change = 1
                    arr[row - 1][col] = 2
                if row + 1 < rowLen and arr[row + 1][col] == 1:
                    change = 1
                    arr[row + 1][col] = 2
                if col - 1 >= 0 and arr[row][col - 1] == 1:
                    change = 1
                    arr[row][col - 1] = 2
                if col + 1 < colLen and arr[row][col + 1] == 1:
                    change = 1
                    arr[row][col + 1] = 2
                if change > 0:
                    min += 1
    for row in range(rowLen):
        for col in range(colLen):
            if arr[row][col] == 1:
                min = -1
    return min


def processOne(arr, row, col, rowLen, colLen):
    change = 0
    if row - 1 >= 0 and arr[row - 1][col] == 1:
        change = 1
        arr[row - 1][col] = 2
    if row + 1 < rowLen and arr[row + 1][col] == 1:
        change = 1
        arr[row + 1][col] = 2
    if col - 1 >= 0 and arr[row][col - 1] == 1:
        change = 1
        arr[row][col - 1] = 2
    if col + 1 < colLen and arr[row][col + 1] == 1:
        change = 1
        arr[row][col + 1] = 2
    return change


import sys
arr = list()
for line in sys.stdin:
    if line == '\n':
        break
    a = line.split()
    arr.append([int(i) for i in a])
print(getMin(arr))
