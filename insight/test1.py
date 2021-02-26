import matplotlib.pyplot as plt
import numpy as np
from pylab import mpl

mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体

year=[2,7,12,17,22,27,32,37,42,47,52,57,62,67,72,77,82,87,92,97]
select=2010
if(select==2010):
    man=[3.08,2.89,3.02,3.89,4.80,3.81,3.72,4.53,4.77,4.03,3.03,3.08,2.24,1.56,1.23,0.85,0.44,0.17,0.04,0.01]
    female=[-2.59,-2.43,-2.60,-3.60,-4.76,-3.76,-3.57,-4.32,-4.59,-3.89,-2.88,-3.02,-2.16,-1.53,-1.24,-0.94,-0.56,-0.26,-0.08,-0.02]
    m100='男 8852 '
    f100='女 25082'
    num='133.28w/0.1%'
    N="六"
elif(select==2000):
    man=[3.03,3.89,5.26,4.26,3.86,4.85,5.26,4.52,3.40,3.54,2.64,1.94,1.74,1.41,1.00,0.58,0.26,0.09,0.02,0.003]
    female=[-2.52,-3.37,-4.83,-4.04,-3.75,-4.62,-4.99,-4.27,-3.14,-3.35,-2.45,-1.80,-1.61,-1.39,-1.06,-0.70,-0.39,-0.16,-0.04,-0.007]
    m100='男 4635 '
    f100='女 13242'
    num='124.26w/0.1%'
    N="五"
fig=plt.figure(figsize=(10,7))

ax1=plt.subplot(111)
ax1.set_xlabel('百分率')
ax1.set_ylabel('年 龄')
ax1.set_title('第'+N+'次（'+str(select)+'）人口普查 :'+num)
rect1 = ax1.bar(x=0,bottom=year , width=female, color='red',height=4, orientation='horizontal')
#第六步，向各条形上添加数据标签
for rec in rect1:
    y=rec.get_y()
    height=-1*rec.get_width()
    ax1.text(-1.005*height-0.5,y+0.5,str(height))
ax1.set_ylim(0,100)
ax1.set_xlim(-5.5,5.5)

rect = ax1.bar(x=0,bottom=year , width=man, color='blue',height=4, orientation='horizontal')
for rec in rect:
    y=rec.get_y()
    height=rec.get_width()
    ax1.text(1.02*height,y+0.8,str(height))
ax1.text(-3.5, 90, '女性')
ax1.text(3.0, 90, '男性')
fig.text(0.7,0.05, '注:100+ '+m100+f100)
plt.plot([0,0],[0,100],color='black');
plt.show()