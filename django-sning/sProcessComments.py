import jieba.analyse
from jieba.posseg import cut
import matplotlib.pyplot as plt
import matplotlib.dates as mdate
import numpy as np
import matplotlib as mpl
from random import choice
from datetime import datetime
from PIL import Image
from wordcloud import WordCloud, ImageColorGenerator, STOPWORDS
from os.path import exists
from os import listdir, mkdir
from sDBHelper import DBHelper
"""
@author: sning
createtime: 2019-01-10
updatetime: 2019-04-10
mark:
"""
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 指定默认字体


class JingDongProcesser:

    comments = None
    invalid = 0
    commentsLen = 0

    score5 = 0
    score4 = 0
    score3 = 0
    score2 = 0
    score1 = 0

    level0 = 0
    level1 = 0
    level2 = 0
    level3 = 0
    level4 = 0
    level5 = 0

    mobile = 0
    iPhone = 0
    Android = 0
    iPad = 0
    WeChat = 0
    QQ = 0
    Other = 0

    def __init__(self, itemId):
        self.itemId = itemId
        self.path = 'gp/static/images/item/%s/' % itemId
        if not exists(self.path):
            mkdir(self.path)
        dbHelper = DBHelper()
        self.comments = list(dbHelper.getCommentsById(self.itemId))
        self.comments.sort(key=lambda x: x[1])
        self.commentsLen = len(self.comments)

        self.monthSet = set()
        for comment in self.comments:
            # 星级分布统计
            if comment[2] == 5:
                self.score5 += 1
            elif comment[2] == 4:
                self.score4 += 1
            elif comment[2] == 3:
                self.score3 += 1
            elif comment[2] == 2:
                self.score2 += 1
            else:
                self.score1 += 1

            if comment[3] == 5:
                self.level5 += 1
            elif comment[3] == 4:
                self.level4 += 1
            elif comment[3] == 3:
                self.level3 += 1
            elif comment[3] == 2:
                self.level2 += 1
            elif comment[3] == 1:
                self.level1 += 1
            else:
                self.level0 += 1

            # 平台分布统计
            if comment[4]:
                self.mobile += 1
            # 来源统计
            if comment[5] == 1:
                self.iPhone += 1
            elif comment[5] == 2:
                self.Android += 1
            elif comment[5] == 3:
                self.iPad += 1
            elif comment[5] == 4:
                self.WeChat += 1
            elif comment[5] == 5:
                self.QQ += 1
            else:
                self.Other += 1

            # 月份集合
            self.monthSet.add(datetime(comment[1].year, comment[1].month, 15))

    def getRandomPng(self):
        files = listdir("shapes/")
        return choice(files)

    def gen_ScoreChart(self):
        # 生成星级分布条形图
        # print(" 一星：", self.score1, "\n", "二星：", self.score2, "\n", "三星：",
        #       self.score3, "\n", "四星：", self.score4, "\n", "五星：", self.score5)
        x = [1, 2, 3, 4, 5]
        y = [self.score1, self.score2, self.score3, self.score4, self.score5]
        fig = plt.figure()
        ax = fig.add_subplot(111)
        ax.set_xlabel('星 级(星)')
        ax.set_ylabel("数 目(条)")
        ax.set_title("ID:%d 的评论星级分布(共%d条)" % (self.itemId, self.commentsLen))
        # 去掉边框
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)
        ax.bar(x, y, color='c')
        for a, b in zip(x, y):
            plt.text(a, b, b, ha='center', va='bottom', fontsize=9)
        # for rect in rects:
        #     height = rect.get_height()
        #     plt.text(rect.get_x() + rect.get_width() / 2, height +
        #              1, str(height), ha="center", va="bottom")
        fig.savefig(self.path + "score.jpg")
        plt.close(fig)

    def gen_TimeChart(self):
        # 生成时间分布折线图
        x = list(self.monthSet)
        x.sort()
        # 统计字典
        mdict = dict(zip([i for i in x], [0 for i in x]))
        for comment in self.comments:
            mdict[datetime(comment[1].year, comment[1].month, 15)] += 1
        y = [i for i in mdict.values()]

        fig = plt.figure(figsize=(11, 8))
        ax = fig.add_subplot(111)
        ax.xaxis.set_major_formatter(
            mdate.DateFormatter('%Y-%m'))  # 设置时间标签显示格式
        ax.set_xlabel('评论发布日期')
        ax.set_ylabel("数 目")
        ax.set_title("ID:%d 的评论时间分布(共%d条)" % (self.itemId, self.commentsLen))
        plt.xticks(x, rotation=60, fontsize=9)
        plt.plot(x, y, 'o-', color='b')
        plt.grid(axis='y')
        # 设置数字标签
        for a, b in zip(x, y):
            plt.text(a, b, b, ha='center', va='bottom', fontsize=9)
        plt.subplots_adjust(left=0.1, right=0.95, top=0.9, bottom=0.13)
        fig.savefig(self.path + "time.jpg")
        # plt.show()
        plt.close(fig)

    def gen_CilentChart(self):
        # 生成客户端分布扇形图
        fig = plt.figure(figsize=(11, 4.4))
        ax = fig.add_subplot(121)
        labels = '移动端（%d条）' % self.mobile, '电脑端（%d条）' % (
            self.commentsLen - self.mobile)  # 设置标签
        m = 100 * self.mobile / self.commentsLen
        sizes = [m, 100 - m]  # 占比，和为100
        colors = ['yellowgreen', 'lightskyblue']  # 颜色
        explode = (0, 0.1)  # 展开第二个扇形，间距为0.1
        plt.pie(sizes, explode=explode, labels=labels, colors=colors, autopct='%1.1f%%', shadow=True,
                startangle=90)  # startangle控制饼状图的旋转方向
        plt.axis('equal')  # 保证饼状图是正圆，否则会有一点角度偏斜
        ax.set_title("ID:%d 的评论平台分布(共%d条)" % (self.itemId, self.commentsLen))

        ax2 = fig.add_subplot(122)
        labels2 = ('其他（%d条）' % self.Other, 'iPad端（%d条）' % self.iPad, 'iPhone端（%d条）' % self.iPhone,
                   '微信购物（%d条）' % self.WeChat, '手机QQ购物（%d条）' % self.QQ, 'Android端（%d条）' % self.Android)
        I = 100 * self.iPhone / self.commentsLen
        A = 100 * self.Android / self.commentsLen
        P = 100 * self.iPad / self.commentsLen
        W = 100 * self.WeChat / self.commentsLen
        O = 100 * self.Other / self.commentsLen
        Q = 100 - I - A - P - W - O
        sizes = [O, P, I, W, Q, A]  # 占比，和为100
        colors = ['silver', 'lime', 'lightskyblue',
                  'gold', 'pink', 'fuchsia']  # 颜色
        explode = (0, 0, 0, 0, 0.1, 0.1)  # 展开第二个扇形，间距为0.1
        plt.pie(sizes, explode=explode, labels=labels2, colors=colors, autopct='%1.1f%%', shadow=True,
                startangle=90)  # startangle控制饼状图的旋转方向
        plt.axis('equal')  # 保证饼状图是正圆，否则会有一点角度偏斜
        ax2.set_title("ID:%d 的评论来源分布(共%d条)" % (self.itemId, self.commentsLen))
        plt.subplots_adjust(left=0.05, right=0.87, top=0.9, bottom=0.13)
        fig.savefig(self.path + "client.jpg")
        # plt.show()
        plt.close(fig)

    def gen_UserLevel(self):
        fig = plt.figure()
        ax2 = fig.add_subplot(111)
        if self.commentsLen < 1:
            plt.close(fig)
            return
        T = 100 * self.level1 / self.commentsLen
        Y = 100 * self.level2 / self.commentsLen
        J = 100 * self.level3 / self.commentsLen
        Z = 100 * self.level4 / self.commentsLen
        P = 100 * self.level5 / self.commentsLen
        O = 100 - T - Y - J - Z - P
        labels = ['银牌会员（%d条）' % self.level2, '金牌会员（%d条）' % self.level3, '钻石会员（%d条）' % self.level4,
                  '铜牌会员（%d条）' % self.level1, 'PLUS会员（%d条）' % self.level5, '其他（%d条）' % self.level0]
        sizes = [Y, J, Z, T, P, O]  # 占比，和为100
        colors = ['fuchsia', 'orange', 'limegreen',
                  'gold', 'cornflowerblue', 'pink']  # 颜色
        explode = (0, 0.1, 0, 0, 0.1, 0)  # 展开第二个扇形，间距为0.1
        plt.pie(sizes,
                explode=explode,
                labels=labels,
                colors=colors,
                autopct='%1.1f%%',
                shadow=True,
                startangle=90,
                textprops={'fontsize': 12, 'color': 'w'}
                )  # startangle控制饼状图的旋转方向
        plt.axis('equal')  # 保证饼状图是正圆，否则会有一点角度偏斜
        ax2.set_title("ID:%d 的消费者分布(共%d条)" % (self.itemId, self.commentsLen))
        plt.subplots_adjust(left=0, right=1.0, top=0.9, bottom=0)
        plt.legend(loc='upper right')
        fig.savefig(self.path + "user.jpg")
        # plt.show()
        plt.close(fig)

    """
Ag 形语素 形容词性语素。形容词代码为 a，语素代码ｇ前面置以A。
a 形容词 取英语形容词 adjective的第1个字母。 
ad 副形词 直接作状语的形容词。形容词代码 a和副词代码d并在一起。 
an 名形词 具有名词功能的形容词。形容词代码 a和名词代码n并在一起。
b 区别词 取汉字“别”的声母。
c 连词 取英语连词 conjunction的第1个字母。
dg 副语素 副词性语素。副词代码为 d，语素代码ｇ前面置以D。
d 副词 取 adverb的第2个字母，因其第1个字母已用于形容词。
e 叹词 取英语叹词 exclamation的第1个字母。
f 方位词 取汉字“方”
g 语素 绝大多数语素都能作为合成词的“词根”，取汉字“根”的声母。
h 前接成分 取英语 head的第1个字母。
i 成语 取英语成语 idiom的第1个字母。
j 简称略语 取汉字“简”的声母。
k 后接成分 
l 习用语 习用语尚未成为成语，有点“临时性”，取“临”的声母。
m 数词 取英语 numeral的第3个字母，n，u已有他用。
Ng 名语素 名词性语素。名词代码为 n，语素代码ｇ前面置以N。
n 名词 取英语名词 noun的第1个字母。
nr 人名 名词代码n和“人(ren)”的声母并在一起。
ns 地名 名词代码n和处所词代码s并在一起。
nt 机构团体 “团”的声母为 t，名词代码n和t并在一起。
nz 其他专名 “专”的声母的第 1个字母为z，名词代码n和z并在一起。
o 拟声词 取英语拟声词 onomatopoeia的第1个字母。
p 介词 取英语介词 prepositional的第1个字母。
q 量词 取英语 quantity的第1个字母。
r 代词 取英语代词 pronoun的第2个字母,因p已用于介词。
s 处所词 取英语 space的第1个字母。
tg 时语素 时间词性语素。时间词代码为 t,在语素的代码g前面置以T。
t 时间词 取英语 time的第1个字母。
u 助词 取英语助词 auxiliary
vg 动语素 动词性语素。动词代码为 v。在语素的代码g前面置以V。
v 动词 取英语动词 verb的第一个字母。
vd 副动词 直接作状语的动词。动词和副词的代码并在一起。
vn 名动词 指具有名词功能的动词。动词和名词的代码并在一起。
w 标点符号 
x 非语素字 非语素字只是一个符号，字母 x通常用于代表未知数、符号。
y 语气词 取汉字“语”的声母。
z 状态词 取汉字“状”的声母的前一个字母。
un 未知词 不可识别词及用户自定义词组。取英文Unkonwn首两个字母。(非北大标准，CSW分词中定义)
    """

    def gen_WordCloud(self):
        comtxt = ''
        for comment in self.comments:
            if len(comment[0]) < 4:
                # self.comments.remove(comment)
                self.invalid += 1
            else:
                comtxt += comment[0] + '。'
        print("评论总数：%d | 无效评论数 %d" % (self.commentsLen, self.invalid))
        result = jieba.analyse.textrank(
            comtxt, topK=150, withWeight=True)
        comtxt = ''
        for k, v in result:
            comtxt += ' %s' % k
        # print(comtxt)
        stopwords = ['此用户未填写评价内容', 'hellip',
                     '还不错', '还可以', '很好', '挺好的', '不错',
                     '很喜欢', '喜欢', '好', '']
        shape = self.getRandomPng()
        # shape = 'bird_face.png'
        bg_color = Image.open("shapes/%s" % shape)
        bg_color = np.array(bg_color)
        fwc = WordCloud(max_words=150,
                        background_color='white',
                        mask=bg_color,
                        font_path='fonts/fz.ttf',  # 设置字体格式，如不设置显示不了中文
                        stopwords=stopwords,  # 设置停用词
                        random_state=100,  # 设置有多少种随机生成状态，即有多少种配色方案
                        max_font_size=150,
                        font_step=1).generate(comtxt)
        isrecolor = False
        if isrecolor:
            imagecolor = ImageColorGenerator(bg_color)
            fwc.recolor(color_func=imagecolor)
        fwc.to_file(self.path + "cloud.png")
        # 将词云图和背景图结合
        bg = Image.open("shapes/%s" % shape).convert('RGBA')
        im = Image.open(self.path + "cloud.png").convert('RGBA')
        img = Image.blend(im, bg, 0.10)
        img.save(self.path + "cloud1.png")


def AnalyseOne(platform_id):
    dbHelper = DBHelper()
    jingDongProcesser = JingDongProcesser(platform_id)
    print("正在分析商品%s" % platform_id)
    jingDongProcesser.gen_ScoreChart()
    jingDongProcesser.gen_TimeChart()
    jingDongProcesser.gen_CilentChart()
    jingDongProcesser.gen_UserLevel()
    jingDongProcesser.gen_WordCloud()
    dbHelper.setAnalyseFinish(platform_id)
    print('分析完成')


def AnalyseAll():
    dbHelper = DBHelper()
    dbHelper.deleteInvalidItem()
    ids = dbHelper.getAllId()
    count = 0
    al = len(ids)
    for cid in ids:
        print('剩余商品数目%d' % (al - count))
        count += 1
        if count < 480:
            continue
        # print('处理商品第%d件商品%d' % (count, cid[0]))
        AnalyseOne(cid[0])
        dbHelper.setAnalyseFinish(cid[0])
    print('本次共分析%d件商品' % count)


if __name__ == '__main__':
    pid = 100000013074
    # gen_DjangoItem(pid)
    AnalyseAll()
    # AnalyseOne(pid)
