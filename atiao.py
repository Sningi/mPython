import xlrd
import os
import matplotlib
import operator
from matplotlib import pyplot as plt 

#配置字体，显示中文
font = {'family': 'MicroSoft Yahei',
        'weight': 'normal',
        'size': 6}
matplotlib.rc("font", **font)

def read_excel(filename):
    if os.path.exists(filename):
        mexcel = xlrd.open_workbook(filename)
        # 获取excel 表1
        sheet0 = mexcel.sheets()[0]
        # 列表生成式提取第一列（表头分类）的内容
        col_names = [sheet0.cell_value(0, i) for i in range(sheet0.ncols)]
        # print(col_names)
        # 各列属性为：
        # ['序号', '开课学期', '课程编号', '课程名称', '成绩', '学分', '总学时', '绩点', '考核方式', '课程属性', '课程性质']

        # 总行数
        row = sheet0.nrows
        all_data = []
        for i in range(1, row):
            # 枚举excel表格的所有行,除表头第一行
            # 定义一门成绩的字段
            one = {}
            for index, name in enumerate(col_names):
                one[name] = sheet0.cell_value(i, index)
            # 格式化一门课程成绩信息,格式如下：
            """
            {
                '序号': 67.0, '开课学期': '2020-2021-1', '课程编号': 8013232.0, 
                '课程名称': '影视鉴赏', '成绩': 89.0,
                '学分': 2.0, '总学时': 32.0, '绩点': '', 
                '考核方式': '考查', '课程属性': '公选', '课程性质': '通识教育选修课'
            }
            """
            all_data.append(one)
        # 返回所有课程的成绩
        return all_data
    else:
        print("成绩单文件不存在")


def analyze_course(data):
    # 统计课程各属性学分比例
    category = dict()
    for course in data:
        if course['课程性质'] not in category:
            # 第一次添加此类课程
            category[course['课程性质']] = course['学分']
        else:
            # 累计这个种类课程学分
            category[course['课程性质']] += course['学分']
    # print(category)
    # 统计结果样例：
    '''
    {
        '通识教育选修课': 17.0, '公共必修课': 30.5, 
        '实践课': 121.0, '学科基础课': 6.0, 
        '学科（专业）基础课': 24.0, '通识教育必修课': 14.0, 
        '专业必修课': 16.0, '专业选修课': 6.0
    }
    '''
    return category

def Pie_chart(data):
    # 绘制学分分布饼图
    #调节图形大小，宽，高
    plt.figure(figsize=(7,5),dpi=200)
    plt.title("18级物流管理二班郑艳修习课程学分分布图")
    #定义饼状图的标签，标签是列表
    labels = [str(i)+"(%.1f)"%(data[i]) for i in data.keys()]
    #每个标签占多大，计算百分比
    #总学分
    count = 0
    for cate in data:
        count += data[cate]

    sizes = [data[cate]/count for cate in data]
    #将某部分外裂出来， 使用括号，将第一块分割出来，数值的大小是分割出来的与其他两块的间隙
    explode = (0.05,0,0,0.02,0,0,0,0.05)

    patches,l_text,p_text = plt.pie(sizes,explode=explode,labels=labels,
                                    labeldistance = 1,autopct = '%3.1f%%',shadow = False,
                                    startangle = 90,pctdistance = 0.6,radius=0.5)

    for t in l_text:
        t.set_size=(30)
    for t in p_text:
        t.set_size=(20)
    # 设置x，y轴刻度一致，这样饼图才能是圆的
    plt.axis('equal')
    plt.legend(prop={"size":6},loc = (0, 0))
    plt.show()

def analyze_course_avg(data):
    # 分析每学期的加权平均分
    category = dict()
    for course in data:
        if course['开课学期'] not in category:
            # 第一次添加这个学期成绩和学分
            score = course['成绩']
            if score == '优':
                score = 95
            elif score == '中':
                score = 80
            elif score =='':
                score = 90
            weight = course['学分']
            category[course['开课学期']] = [(score, weight)]
        else:
            # 累计这个学期成绩和学分
            score = course['成绩']
            weight = course['学分']
            if score == '优':
                score = 95
            elif score == '中':
                score = 80
            elif score =='':
                score = 90
            category[course['开课学期']].append((score, weight))
    return category

def get_per_avg(avg_data):
    result = list()
    # 获取每学期的总学分和加权平均分
    for term in avg_data:
        one_term = {}
        all_cout = 0
        all_grade = 0
        for course in avg_data[term]:
            # 累计该学期学分
            all_cout += course[1]
            # 累计加权总分
            all_grade += course[0]* course[1]
        result.append({term:(all_cout, all_grade/all_cout)})
    # 数据格式：
    # [{'2018-2019-1': (19.5, 84.07179487179488)}, 
    # {'2018-2019-2': (31.5, 81.95238095238095)}, 
    # {'2019-2020-1': (21.0, 87.33333333333333)},
    # {'2019-2020-2': (39.5, 90.27848101265823)}, 
    # {'2020-2021-1': (21.0, 87.80952380952381)}]
    return result

def avg_chart(data):
    plt.figure(figsize=(5,4),dpi=200)
    plt.title("18级物流管理二班郑艳各学期加权平均分及学期学分分布图")
    plt.xlabel('学期')
    plt.ylabel('平均分/学期总学分')
    x = []
    y = []
    z = []
    for term in data:
        for key in term:
            x.append(key)
            y.append(term[key][0])
            z.append(term[key][1])

    #加权平均分折线图    
    line = plt.plot(x, z, marker='',
                label='加权平均分', color='blue', linewidth=1)
    for a, b in zip(x, z):
        plt.text(a, b, "%.1f" % b, ha='right', va='bottom', fontsize=5)


    
    #总学分折现图
    # line = plt.plot(x, y, marker='.', linestyle='-',
    #                 label='总学分', color='blue', linewidth=1)
    # for a, b in zip(x, y):
    #     plt.text(a, b, "%.1f" % b, ha='right', va='bottom', fontsize=5)

    rects = plt.bar(x,y,color='lightblue',label='每学期学分',width = 0.5)
    #为柱状图添加高度值
    for rect in rects:
        x = rect.get_x()
        height = rect.get_height()
        plt.text(x+0.2,1.01*height,str(height))


    ax1 = plt.gca()
    ax1.spines['top'].set_visible(False)
    ax1.spines['right'].set_visible(False)
    plt.legend(loc=4)
    plt.show()

def top_5(data):
    # 升序
    for d in data:
        if d["成绩"] == '优':
            d["成绩"] = 95
        elif d["成绩"] == '中':
            d["成绩"] = 80
        elif d["成绩"] =='':
            d["成绩"] = 90
    # 对课程按成绩排序
    data = sorted(data, key=operator.itemgetter('成绩'))
    return data[-5:],data[:5]

def main():
    data = read_excel("./成绩表.xlsx")
    result = analyze_course(data)
    print("分析1:大学课程类型比重")
    print(result)
    Pie_chart(result)
    avg_data = analyze_course_avg(data)
    per_avg = get_per_avg(avg_data)
    avg_chart(per_avg)
    print("\n分析2:各个学期加权平均分及总学分")
    print(per_avg)

    tmax,tmin = top_5(data)
    tmax.reverse()
    print("\n分析3:成绩最高和最低的5门课程")
    print('****最高分top5****')
    for m in tmax:
        print(m['课程名称'], m['成绩'])
    print('\n****最低分top5****')
    for i in tmin:
        print(i['课程名称'], i['成绩'])






if __name__ == "__main__":
    # 依赖安装
    # pip install xlrd==1.2.0
    # pip install matplotlib
    main()
