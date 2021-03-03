

def chart_max_99m2():
    pass


def chart_max_144m2():
    pass


def chart_min_144m2():
    pass


def chart_new():
    pass


def chart_old():
    pass


def chart_all(a=False, b=False, c=False, d=False, e=False):
    pass


def main():
    import numpy as np
    from matplotlib import pyplot as plt
    from scipy.interpolate import make_interp_spline

    x = np.array([6, 7, 8, 9, 10, 11, 12])
    y = np.array([1.53E+03, 5.92E+02, 2.04E+02, 7.24E+01, 2.72E+01, 1.10E+01, 4.70E+00])
    x_smooth = np.linspace(x.min(), x.max(), 300)
    y_smooth = make_interp_spline(x, y)(x_smooth)
    plt.plot(x_smooth, y_smooth)
    plt.show()



if __name__ == "__main__":
    main()