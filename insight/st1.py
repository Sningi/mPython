from matplotlib.pyplot import *

x = [1, 2, 3, 4, 5, 6]
y = [3, 4, 6, 7, 3, 2]


def f1():
    # 水平条形图
    barh(x, y)


def f2():
    # 折现
    plot(x, y)


def f3():
    # 柱状图
    bar(x, y)


def f4():
    # 水平柱状图
    barh(x, y)


def f5():
    # 叠加柱状图
    bar(x, y)
    y1 = [2, 3, 4, 5, 6, 7]
    bar(x, y1, bottom=y, color='r')


def f6():
    # 箱线图
    boxplot(y)


def f7():
    # 散点图
    scatter(x, y)


def f8():
    dataset = [1, 3, 5, 7, 8, 3, 4, 5, 6, 7, 1, 2, 34,
               3, 4, 4, 5, 6, 3, 2, 2, 3, 4, 5, 6, 7, 4, 3]
    subplot(1, 2, 1)
    boxplot(dataset, vert=False)
    subplot(1, 2, 2)
    # 直方图
    hist(dataset)


def main():
    f5()
    show()


if __name__ == '__main__':
    main()
