import pandas as pd
import matplotlib.pyplot
matplotlib.style.use('ggplot')
budget = pd.read_csv("db.csv")
budget = budget.sort_values('amount', ascending=False)[:2]
matplotlib.style.use('ggplot')
budget_plot = budget.plot(kind="bar", x=budget["detail"],
                          title="MN Capital Budget - 2014",
                          legend=False)
fig = budget_plot.get_figure()
