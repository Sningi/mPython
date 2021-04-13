import xlrd
import os
def read_excel(filename):
    if os.path.exists(filename):
        mexcel = xlrd.open_workbook(filename)
        # 获取excel 表1
        sheet0 = mexcel.sheets()[0]
        #列表生成式提取第一列（表头分类）的内容
        col_names = [sheet0.cell_value(0, i) for i in range(sheet0.ncols)]
        # print(col_names)
        # 各列属性为：
        # ['序号', '开课学期', '课程编号', '课程名称', '成绩', '学分', '总学时', '绩点', '考核方式', '课程属性', '课程性质']
        
        # 总行数
        row = sheet0.nrows
        for i in range(row):
            print(sheet0.cell_value(i, 0))

    else:
        print("成绩单文件不存在")



def main():
    data = read_excel("./成绩表.xlsx")

if __name__ == "__main__":
    #依赖安装 
    # pip install xlrd==1.2.0
    main()