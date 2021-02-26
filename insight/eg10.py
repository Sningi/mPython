import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
import random
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from pylab import mpl

mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体
fig = plt.figure()

def main():
    f2()
    plt.show()
def f1():
    #3D图形
    ax = fig.add_subplot(111,projection='3d')
    n_angles = 36
    n_radii = 8
    radii = np.linspace(0.125, 1.0, n_radii)
    angles = np.linspace(0, 2*np.pi, n_angles, endpoint=False)
    angles = np.repeat(angles[..., np.newaxis], n_radii, axis=1)
    x = np.append(0, (radii*np.cos(angles)).flatten())
    y = np.append(0, (radii*np.sin(angles)).flatten())
    z = np.sin(-x*y)
    ax.plot_trisurf(x,y,z,cmap=cm.jet, lw=0.2)


def f2():
    #印刷
    t = np.arange(0.0, 1.0+0.01, 0.01)
    s = np.cos(4 * np.pi *t) * np.sin(np.pi*t/4) + 2
    #plt.rc('text', usetex=True)  #未安装Latex
    plt.rc('font', **{'family':'sans-serif','sans-serif':['Helvetica'],'size':16})
    plt.plot(t, s, alpha=0.55)
    plt.annotate(r'$\cos(4 \times \pi \times {t}) \times \sin(\pi \times \frac{t}{4}) + 2$',xy=(.9, 2.2), xytext=(.5, 2.6),color='r', arrowprops={'arrowstyle':'->'})
    plt.text(.01, 2.7, r'$\alpha, \beta, \gamma, \Gamma, \pi, \Pi, \phi, \varphi, \Phi$')
    plt.xlabel(r'time (s)')
    plt.ylabel(r'y values(W)')
    plt.title(r"Hello python visualization.")
    plt.subplots_adjust(top=0.8)

def f3():
    label_list = ['2014', '2015', '2016', '2017']    # 横坐标刻度显示值
    num_list1 = [20, 30, 15, 35]      # 纵坐标值1
    num_list2 = [15, 30, 40, 20]      # 纵坐标值2
    x = range(len(num_list1))
    """
    绘制条形图
    left:长条形中点横坐标
    height:长条形高度
    width:长条形宽度，默认值0.8
    label:为后面设置legend准备
    """
    rects1 = plt.bar(left=x, height=num_list1, width=0.4, alpha=0.8, color='red', label="一部门")
    rects2 = plt.bar(left=[i + 0.4 for i in x], height=num_list2, width=0.4, color='green', label="二部门")
    plt.ylim(0, 50)     # y轴取值范围
    plt.ylabel("数量")
    """
    设置x轴刻度显示值
    参数一：中点坐标
    参数二：显示值
    """
    plt.xticks([index + 0.2 for index in x], label_list)
    plt.xlabel("年份")
    plt.title("某某公司")
    plt.legend()     # 设置题注
    # 编辑文本
    for rect in rects1:
        height = rect.get_height()
        plt.text(rect.get_x() + rect.get_width() / 2, height+1, str(height), ha="center", va="bottom")
    for rect in rects2:
        height = rect.get_height()
        plt.text(rect.get_x() + rect.get_width() / 2, height+1, str(height), ha="center", va="bottom")

def f4():
    ax = fig.add_subplot(111, projection='3d')
    for z in [2015, 2016, 2017]:
        xs = range(1, 13)
        ys = 1000 * np.random.rand(12)
        color = plt.cm.Set2(random.choice(range(plt.cm.Set2.N)))
        ax.bar(xs, ys, zs=z, zdir='y', color=color, alpha=0.8)
    ax.xaxis.set_major_locator(mpl.ticker.FixedLocator(xs))
    ax.yaxis.set_major_locator(mpl.ticker.FixedLocator(ys))
    ax.set_xlabel('M')
    ax.set_ylabel('Y')
    ax.set_zlabel('Sales')
if __name__ == '__main__':
    main()