#!/usr/bin/env python
# for x in 'ning':
#     print(x)

# x = 1
# y = 1
# print(bin(x + y)[2:])
from docxtpl import DocxTemplate

data_dic = {
    'title': '并不清楚你在讲什么',
    'isbn': '鬼知道索书号是什么',
    'content': '内容为空',
    'commit': '你的观点只是你的观点'
}

doc = DocxTemplate('/home/sning/Documents/temp.docx')  # 加载模板文件
doc.render(data_dic)  # 填充数据
doc.save('/home/sning/Documents/result.docx')  # 保存目标文件
