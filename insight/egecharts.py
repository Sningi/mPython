from pyecharts import Bar
from pyecharts import Geo
from pyecharts import Map
import pandas as pd
from pyecharts import Gauge
from pyecharts import Liquid
from pyecharts import EffectScatter


def main():
    f11()


def f11():
    v1 = [10, 20, 30, 40, 50, 60]
    v2 = [25, 20, 15, 10, 60, 33]
    es = EffectScatter("动态散点图示例")
    es.add("effectScatter", v1, v2)
    es.render()


def f10():
    liquid = Liquid("水球图示例")
    liquid.add("Liquid", [0.6])
    liquid.render()


def f9():
    value = [155, 10, 66, 78, 33, 80, 190, 53, 49.6]
    attr = ["福建", "山东", "北京", "上海", "甘肃", "新疆", "河南", "广西", "西藏"]
    map = Map("Map 结合 VisualMap 示例", width=1200, height=600)
    map.add("", attr, value, maptype='china',
            is_visualmap=True, visual_text_color='#000')
    # map.show_config()
    map.render()


def f8():
    data = [("海门", 9), ("鄂尔多斯", 12), ("招远", 12),
            ("舟山", 12), ("齐齐哈尔", 14), ("盐城", 15)]
    geo = Geo("全国主要城市空气质量", "data from pm2.5", title_color="#fff", title_pos="center",
              width=1200, height=600, background_color='#404a59')
    attr, value = geo.cast(data)
    geo.add("", attr, value, type="effectScatter",
            is_random=True, effect_scale=5)
    geo.render()


def f7():
    gauge = Gauge("仪表盘示例")
    gauge.add("业务指标", "完成率", 66.66, color="blue")
    gauge.add("业务", "成率", 36.66, color="black")
    gauge.render()


data = [("广东", 10430.03), ("山东", 9579.31), ("河南", 9402.36), ("四川", 8041.82), ("江苏", 7865.99), ("河北", 7185.42), ("湖南", 6568.37), ("安徽", 5950.1), ("浙江", 5442), ("湖北", 5723.77), ("广西", 4602.66), ("云南", 4596.6), ("江西", 4456.74), ("辽宁", 4374.63), ("黑龙江", 3831.22), ("陕西", 3732.74), ("山西",
                                                                                                                                                                                                                                                                                      3571.21), ("福建", 3552), ("重庆", 2884), ("贵州", 3476.65), ("吉林", 2746.22), ("甘肃", 2557.53), ("内蒙古", 2470.63), ("上海", 2301.391), ("台湾", 2316.2), ("新疆", 2181.33), ("北京", 1961.2), ("天津", 1293.82), ("海南", 867.15), ("香港", 709.76), ("青海", 562.67), ("宁夏", 630.14), ("西藏", 300.21), ("澳门", 55.23)]
data = pd.DataFrame(data)
data.columns = ['city', 'popu']


def f6():
    map = Map("各省市人口数", "单位：万人", title_color="#fff", title_pos="center",
              width=1200,  height=600, background_color='#404a59')
    attr = data['city']
    value = data['popu']
    map.add("", attr, value, visual_range=[
            0, 5000], visual_text_color="#fff",        symbol_size=15, is_visualmap=True, is_label_show=True)


def f5():
    value = [155, 10, 66, 78, 33, 80, 190, 53, 49.6]
    attr = ["福建", "山东", "北京", "上海", "甘肃", "新疆", "河南", "广西", "西藏"]
    map = Map("Map 结合 VisualMap 示例", width=1200, height=600)
    map.add("", attr, value, maptype='china',
            is_visualmap=True, visual_text_color='#000')
    map.render()


def f1():
    bar = Bar("我的第一个图表", "这里是副标题")
    bar.add("服装", ["衬衫", "羊毛衫", "雪纺衫", "裤子", "高跟鞋", "袜子"],
            [5, 20, 36, 10, 75, 90])
    # bar.show_config()
    bar.render()


def f2():
    bar = Bar("标记线和标记点示例")
    bar.add("商家A", ["衬衫", "羊毛衫", "雪纺衫", "裤子", "高跟鞋", "袜子"],
            [5, 20, 36, 10, 75, 90], mark_point=["average"])
    bar.add("商家B", ["衬衫", "羊毛衫", "雪纺衫", "裤子", "高跟鞋", "袜子"],
            [5, 15, 30, 6, 50, 60], mark_line=["min", "max"])
    bar.render()


attr = ["衬衫", "羊毛衫", "雪纺衫", "裤子", "高跟鞋", "袜子"]
v1 = [5, 20, 36, 10, 75, 90]
v2 = [5, 15, 30, 6, 50, -60]

year = [2, 7, 12, 17, 22, 27, 32, 37, 42, 47,
        52, 57, 62, 67, 72, 77, 82, 87, 92, 97]
man = [3.08, 2.89, 3.02, 3.89, 4.80, 3.81, 3.72, 4.53, 4.77, 4.03,
       3.03, 3.08, 2.24, 1.56, 1.23, 0.85, 0.44, 0.17, 0.04, 0.01]
female = [-2.59, -2.43, -2.60, -3.60, -4.76, -3.76, -3.57, -4.32, -4.59, -
          3.89, -2.88, -3.02, -2.16, -1.53, -1.24, -0.94, -0.56, -0.26, -0.08, -0.02]


def f3():
    bar = Bar("2010")
    bar.add("男性", year, man)
    bar.add("女性", year, female, is_convert=True)
    bar.render()


def f4():
    data = [
        ("海门", 9), ("鄂尔多斯", 12), ("招远", 12), ("舟山", 12), ("齐齐哈尔", 14), ("盐城", 15),
        ("赤峰", 16), ("青岛", 18), ("乳山", 18), ("金昌", 19), ("泉州", 21), ("莱西", 21),
        ("日照", 21), ("胶南", 22), ("南通", 23), ("拉萨", 24), ("云浮", 24), ("梅州", 25)]
    geo = Geo("全国主要城市空气质量", "data from pm2.5", title_color="#fff", title_pos="center",
              width=1200, height=600, background_color='#404a59')
    attr, value = geo.cast(data)
    geo.add("", attr, value, visual_range=[
            0, 200], visual_text_color="#fff", symbol_size=15, is_visualmap=True)
    geo.render()


if __name__ == '__main__':
    main()
