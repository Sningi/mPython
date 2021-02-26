try:
    from cutecharts.charts import Line
except Exception:
    print('please install by: pip install cutecharts')
    exit()

chart = Line("XXXX")
chart.set_options(
    labels=["6", "12", "18", "24", "30", "36", "42"], 
    x_label="TimeLine(m)", 
    y_label="RMB",
)
chart.add_series("series-A", [6, 8, 10, 13, 15, 16])
chart.render()