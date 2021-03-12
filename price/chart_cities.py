
from datetime import datetime
import matplotlib.pyplot as plt


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


def chart_max_99m2(data_axis, raw_data):
    pass


def chart_max_144m2(data_axis, raw_data):
    pass


def chart_min_144m2(data_axis, raw_data):
    pass


def chart_new(data_axis, raw_data):
    l_visit = [100, 101, 105]
    plt.plot(data_axis, l_visit, 'o-')
    plt.text(data_axis[-1], l_visit[-1], l_visit[-1],
             ha='right', va='bottom', fontsize=10)


def chart_old(data_axis, raw_data):
    # import numpy as np
    # x_smooth = np.linspace(9, 12, 12)
    # from scipy.interpolate import make_interp_spline
    # y_smooth = make_interp_spline([i for i in range(1,13)], raw_data)(x_smooth)
    plt.plot(data_axis, raw_data, 'o-')


def get_data(months, city='bj'):
    import random
    data = [100+month[1]*random.randint(1, 10) for month in months]
    return data


def chart_all(date_start, date_end, city='bj', min=False, med=False, max=False, new=False, old=False):

    plt.figure(figsize=(4, 4))
    plt.title('price')
    plt.xlabel('date')
    plt.ylabel('Increase')

    months = gen_months(date_start, date_end)
    xs = [datetime.strptime(d, '%Y/%m').date()
          for d in ['{0}/{1}'.format(month[0], month[1]) for month in months]]

    data = get_data(months, city)
    if min:
        chart_max_99m2(xs, data)
    if med:
        chart_max_144m2(xs, data)
    if max:
        chart_max_144m2(xs, data)
    if new:
        chart_new(xs, data)
    if old:
        chart_old(xs, data)

    plt.gcf().autofmt_xdate()  # 自动旋转日期标记
    plt.show()


if __name__ == "__main__":
    chart_all('202001', '202012', city='bg', new=False, old=True)
    # eg1()
