def question1(arr):
    colLen = len(arr[0])
    rowLen = len(arr)
    for col in range(colLen + rowLen - 1):
        for row in range(rowLen):
            if col - row < 0 or col - row > colLen - 1:
                continue
            print(arr[row][col - row])


if __name__ == '__main__':
    arr = ((1, 2, 3), (4, 5, 6), (7, 8, 9), (10, 11, 12))
    question1(arr)
