import matplotlib.pyplot as plt
from pylab import mpl
import numpy as np
import xlrd

mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 指定默认字体
# 首先实例化一个book对象
book00 = xlrd.open_workbook("2000.xlsx")
# 然后获取这个book的所有sheet名称,返回一个列表
sheetName = book00.sheet_names()
# 获取sheet类的一个对象，也就是说，如果知道每个sheet的名字的话，就可以直接用sheet的名字来实例化它了
sheet00 = book00.sheet_by_name(sheetName[0])
# 然后我们去获得这个对象的列的数据,比如下面一行获得是sheet1也就是第一个sheet的第一列的前40个数据，格式为一个列表
female00 = sheet00.col_values(3)[0:20]
man00 = sheet00.col_values(2)[0:20]

book10 = xlrd.open_workbook("2010.xlsx")
sheetName = book10.sheet_names()
sheet10 = book10.sheet_by_name(sheetName[0])
female10 = sheet10.col_values(3)[0:20]
man10 = sheet10.col_values(2)[0:20]

year = [2, 7, 12, 17, 22, 27, 32, 37, 42, 47,
        52, 57, 62, 67, 72, 77, 82, 87, 92, 97]
fig = plt.figure(figsize=(14, 7))
ax = fig.add_subplot(111)

x = range(len(year))
rects1 = ax.bar(x=x, height=female00, width=0.4, color='blue', label="00年")
rects2 = ax.bar(x=[i + 0.4 for i in x], height=female10,
                width=0.4, color='pink', label="10年")
# rects1 = ax.plot(female00)
# rects2 = ax.plot(female10)
plt.xticks([index + 0.2 for index in x], year)
# for rect in rects1:
#     height = int(rect.get_height())
#     plt.text(rect.get_x() + rect.get_width() / 2, height +
#              1, str(height), ha="center", va="bottom")
for a, b in zip(x, female00):
    plt.text(a, b, b - 10, ha='center', va='bottom', fontsize=9,)
for a, b in zip(x, female10):
    plt.text(a, b, b + 10, ha='center', va='bottom', fontsize=9,)
# for rect in rects2:
#     height = int(rect.get_height())
#     plt.text(rect.get_x() + rect.get_width() / 2, height +
#              1, str(height), ha="center", va="bottom")

plt.title('2000与2010人口消逝')
plt.xlabel('年龄')
plt.ylabel('人数')
plt.legend()     # 设置题注
plt.show()
