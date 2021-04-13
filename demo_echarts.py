import os
from pyecharts import options as opts
from pyecharts.charts import Geo
from pyecharts.globals import ChartType, SymbolType

c_and_d = [("杭州", 2), ("保定", 1),
           ("石家庄", 2), ("南通", 1), ("深圳", 1),
           ("南京", 2), ("温州", 1)]

study = [("鹿邑", 16), ("淮阳", 3), ("武汉", 4)]


journey = [("郑州", 1), ("保定", 1), ("太和县", 1), ("南京", 1),
           ("上海", 1), ("厦门", 1), ("包头", 1), ("长沙", 1),
           ('衡阳', 1), ('信阳', 1), ('登封', 1),
           ('舟山',1),('黄山',1),('杭州',1),("北京", 1),]

work = [("北京", 1),("苏州", 4)]
# p = [("浙江", 1), ("江苏", 1), ("河北", 1), ("广东", 1)]

c = (
    Geo(init_opts=opts.InitOpts(width="1200px", height="800px"))
    .add_schema(maptype="china")
    
    .add(
        "工作",
        work,
        type_=ChartType.EFFECT_SCATTER,
        color="tomato",
        point_size=3,
        symbol_size=2,
        label_opts=opts.LabelOpts(
            is_show=True, formatter='{b}', font_size=10)
    )
    .add(
        "出差",
        c_and_d,
        type_=ChartType.EFFECT_SCATTER,
        color="blue",
        point_size=3,
        symbol_size=2,
        label_opts=opts.LabelOpts(
            is_show=True, formatter='{b}', font_size=10)
    )
    .add(
        "旅游",
        journey,
        type_=ChartType.EFFECT_SCATTER,
        color="fuchsia",
        point_size=3,
        symbol_size=2,
        label_opts=opts.LabelOpts(
            is_show=True, formatter='{b}', font_size=10)
    )
    .add(
        "教育",
        study,
        type_=ChartType.EFFECT_SCATTER,
        color="green",
        point_size=3,
        symbol_size=2,
        label_opts=opts.LabelOpts(
            is_show=True, formatter='{b}', font_size=10)
    )
    # .add(
    #     "geo",
    #     [("苏州", i[0])for i in c_and_d if i[0]!='苏州'],
    #     type_=ChartType.LINES,
    #     effect_opts=opts.EffectOpts(
    #         symbol=SymbolType.ARROW, symbol_size=2, color="red"
    #     ),
    #     symbol_size=4,
    #     linestyle_opts=opts.LineStyleOpts(curve=0.2,color="green"),
    #     label_opts=opts.LabelOpts(is_show=False)
    # )
    .set_global_opts(title_opts=opts.TitleOpts(title="Geo-Lines"))
    .render("geo_lines.html")
)
os.system("geo_lines.html")
