import numpy
from pandas import read_excel
df = read_excel("./成绩表.xlsx")
data = df.groupby(by=['开课学期','课程性质',])['成绩'].agg([('最低分','min'),('最高分','max'),('平均分','mean')])
print(data)

# print(data.agg('max'))