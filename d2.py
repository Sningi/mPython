from pyecharts import options as opts
from pyecharts.charts import Geo
from pyecharts.faker import Faker

p = [("浙江",1), ("江苏",1),("河北",1),("广东",1)]

c = (
    Geo()
    .add_schema(maptype="china")
    
    .add("geo", p)
    .set_series_opts(label_opts=opts.LabelOpts(is_show=True,formatter='{b}'))
    .set_global_opts(
        title_opts=opts.TitleOpts(title="Geo-基本示例"),
        visualmap_opts=opts.VisualMapOpts(max_=1, is_piecewise=True,
                                          pieces=[
                                            {"max": 1, "min": 1, "label": "去过", "color": "#4EA397"},
                                            {"max": 0, "min": 0, "label": "未去过", "color": "#FFFFFF"},
                                            ])  #最大数据范围，分段
                                         
    )
    .render("geo_base.html")
)
import os
os.system("geo_base.html")
