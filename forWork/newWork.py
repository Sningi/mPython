# -*- coding:utf-8 -*-

# 数组全区间极差之和


class poorSum:
    # array 二维列表
    def Find(self, N, array):
        # write code here
        num = 0
        for i in range(N - 1):
            for j in range(i + 1, N):
                num += (max(array[i:j + 1]) - min(array[i:j + 1]))
        return num


def testPoorSum():
    arr = (1, 2, 3, 4)
    N = len(arr)
    s = poorSum()
    num = s.Find(N, arr)
    print(num)


def countCard(arr):
    cardAmount = [0 for i in range(13)]
    for i in range(len(arr)):
        if arr[i] == 'A':
            cardAmount[0] += 1
        elif arr[i] == 'T':
            cardAmount[9] += 1
        elif arr[i] == 'J':
            cardAmount[10] += 1
        elif arr[i] == 'Q':
            cardAmount[11] += 1
        elif arr[i] == 'K':
            cardAmount[12] += 1
        else:
            cardAmount[int(arr[i]) - 1] += 1
    return cardAmount

# 地主最快出牌轮次


def testCard():
    # array 二维列表
    array = '8K67A65K27T59K346AK2'
    cardAmount = countCard(array)
    print(cardAmount)


if __name__ == '__main__':
    testCard()
