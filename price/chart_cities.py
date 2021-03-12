
from xlsx_process import rd_month_t4_t5
from muitls import gen_months
from datetime import datetime
import matplotlib.pyplot as plt
import matplotlib

font = {'family': 'MicroSoft Yahei',
        'weight': 'normal',
        'size': 8}

matplotlib.rc("font", **font)


def eg1():
    import numpy as np
    from matplotlib import pyplot as plt
    from scipy.interpolate import make_interp_spline

    x = np.array([6, 7, 8, 9, 10, 11, 12])
    y = np.array([1.53E+03, 5.92E+02, 2.04E+02,
                  7.24E+01, 2.72E+01, 1.10E+01, 4.70E+00])
    x_smooth = np.linspace(x.min(), x.max(), 300)
    y_smooth = make_interp_spline(x, y)(x_smooth)
    plt.plot(x_smooth, y_smooth, 'g-')
    plt.show()


def chart(x, y, label="", color='blue', marker='o', linestyle='-'):
    line = plt.plot(x, y, marker=marker, linestyle=linestyle,
                    label=label, color=color, linewidth=1)
    c = 0
    for a, b in zip(x, y):
        if c%2 == 0:
            plt.text(a, b, b, ha='right', va='bottom', fontsize=8)
        c+=1

def get_data_t4_t5(months, city='北京', sheet=4, col="D"):
    data = []
    for month in months:
        data.append(rd_month_t4_t5(month[0], month[1], city, sheet, col))
    return data


def chart_all(date_start, date_end, city='北京', min=False, med=False, max=False, new=False, old=False):
    months = gen_months(date_start, date_end)
    ml = len(months)
    # plt.figure(figsize=(3*(1.0+ml/6), 5))
    # plt.title("2020"+city+"（2015定基比）")
    plt.xlabel('date')
    plt.ylabel('Increase')

    xs = [datetime.strptime(d, '%Y/%m').date()
          for d in ['{0}/{1}'.format(month[0], month[1]) for month in months]]
    # xs.insert(0,datetime.strptime("2010/01", '%Y/%m').date())
    # data.insert(0,100)
    if min:
        data = get_data_t4_t5(months, city, 5, "D")
        chart(xs, data, label="二手<90m2",marker='*', color="pink")
        data = get_data_t4_t5(months, city, 4, "D")
        chart(xs, data, label="新建<90m2",marker='*',color="blue")
    if med:
        data = get_data_t4_t5(months, city, 5, "G")
        chart(xs, data, label="二手<144m2",marker='v', color="powderblue")
        data = get_data_t4_t5(months, city, 4, "G")
        chart(xs, data, label="新建<144m2",marker='v',color="purple")
    if max:
        data = get_data_t4_t5(months, city, 5, "J")
        chart(xs, data, label="二手>144m2", marker='.',color="lawngreen")
        data = get_data_t4_t5(months, city, 4, "J")
        chart(xs, data, label="新建>144m2", marker='.',color="greenyellow")
    if new:
        chart(xs, data)
    if old:
        chart(xs, data)

    plt.gcf().autofmt_xdate()  # 自动旋转日期标记
    ax1 = plt.gca()
    ax1.spines['top'].set_visible(False)
    ax1.spines['right'].set_visible(False)
    plt.legend()
    # ax1.spines['bottom'].set_visible(False)
    # ax1.spines['left'].set_visible(False)


if __name__ == "__main__":
    plt.figure(figsize=(3*(1.0+24/6), 5))
    plt.title("2020"+'杭州'+"（2015定基比）")
    chart_all('202001', '202012', city='杭州', min=True, med=False,max=False)
    chart_all('201501', '201512', city='杭州', min=True, med=False,max=False)
    plt.show()

    # eg1()
