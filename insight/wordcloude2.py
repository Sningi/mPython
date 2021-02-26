# coding:utf-8
import jieba
import matplotlib.pyplot as plt
from wordcloud import WordCloud, ImageColorGenerator, STOPWORDS
# from scipy.misc import imread
from PIL import Image
import numpy as np


def addselfdict():
    items = ['硕风和叶', '苏语凝', '穆如寒江', '牧云珠', '牧云笙']
    for item in items:
        jieba.add_word(item)


def getNovleContent(novel):
    novletext = open(novel).read()
    # addselfdict()
    hmseg = jieba.cut(novletext, cut_all=True)
    seg_space = ' '.join(hmseg)
    # print(seg_space)
    return seg_space


def setStopWords(stopwords_path):
    stopwordlist = set(STOPWORDS)
    f_stop = open(stopwords_path)
    try:
        f_stop_text = f_stop.read()
    finally:
        f_stop.close()
    f_stop_seg_list = f_stop_text.split('\n')
    for val in f_stop_seg_list:
        stopwordlist.add(val)
    return stopwordlist


def Sningwordcloud(shapes, novel_content, isrecolor, stopwords, font_path="font/华康少女文字W5.TTF"):
    bg_color = Image.open("shapes/bgpng/" + shapes + ".png")
    bg_color = np.array(bg_color)
    fwc = WordCloud(max_words=300,
                    background_color='white',
                    mask=bg_color,
                    font_path=font_path,  # 设置字体格式，如不设置显示不了中文
                    stopwords=stopwords,  # 设置停用词
                    random_state=100,  # 设置有多少种随机生成状态，即有多少种配色方案
                    max_font_size=200,
                    font_step=1).generate(novel_content)
    if isrecolor:
        imagecolor = ImageColorGenerator(bg_color)
        fwc.recolor(color_func=imagecolor)
    fwc.to_file("result/" + shapes + ".png")
    fwc = image_diejia(shapes)
    plt.figure(figsize=(12, 7))
    plt.imshow(fwc, interpolation='bilinear')
    plt.axis("off")
    # plt.show()


def image_diejia(shapes):
    # 将词云图和背景图结合
    bg = Image.open("shapes/bgpng/" + shapes + ".png").convert('RGBA')
    im = Image.open("result/" + shapes + ".png").convert('RGBA')
    img = Image.blend(im, bg, 0.1)
    img.save("result/" + shapes + "1.png")
    return img


def main():

    stopwords_path = 'txt/stopwords.txt'      # 停用词词表
    shapes = 'water_dove'               # 词云形状
    novel = 'txt/九州海上牧云记.txt'               # 文章来源
    print(novel)
    isrecolor = True                        # 是否重绘颜色
    stopwords = setStopWords(stopwords_path)
    novel_content = getNovleContent(novel)
    Sningwordcloud(shapes, novel_content, isrecolor, stopwords)


if __name__ == '__main__':
    main()
