import os
import shutil


def f1():
    print(os.getcwd())
    os.chdir("/home/sning")
    print(dir(os))
    shutil.copyfile(
        os.path.expandvars('$HOME') +
        '/114.jpg',
        '/home/sning/116.jpg')


def f2():
    import numpy as np
    import matplotlib.pyplot as plt

    labels = 'A', 'B', 'C', 'D'
    fracs = [15, 30.55, 180.44, 10]
    explode = [0.00, 0.00, 0.0, 0.00]  # 0.1 凸出这部分，
    # set this , Figure is round, otherwise it is an ellipse
    plt.axes(aspect=1)
    # autopct ，show percet
    colors = "#19CAAD", "#D1BA74", "#BEEDC7", "#ECAD9E"
    plt.pie(x=fracs, labels=labels, explode=explode, autopct='%3.1f %%', colors=colors,
            shadow=True, labeldistance=1.1, startangle=90, pctdistance=0.6

            )
    '''
    labeldistance，文本的位置离远点有多远，1.1指1.1倍半径的位置
    autopct，圆里面的文本格式，%3.1f%%表示小数有三位，整数有一位的浮点数
    shadow，饼是否有阴影
    startangle，起始角度，0，表示从0开始逆时针转，为第一块。一般选择从90度开始比较好看
    pctdistance，百分比的text离圆心的距离
    patches, l_texts, p_texts，为了得到饼图的返回值，p_texts饼图内部文本的，l_texts饼图外label的文本
    '''
    plt.show()


def f3():
    pass


if __name__ == '__main__':
    f2()
