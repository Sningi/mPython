import jieba.analyse
from PIL import Image, ImageSequence
import numpy as np
import matplotlib.pyplot as plt
from wordcloud import WordCloud, ImageColorGenerator, STOPWORDS


def song(file_txt, shapes, fp):
    lyric = ''
    f = open(file_txt, 'r')
    for i in f:
        lyric += f.read()

    result = jieba.analyse.textrank(lyric, topK=500, withWeight=True)
    keywords = dict()
    for i in result:
        keywords[i[0]] = i[1]
    # print(keywords)

    stopwords = set(STOPWORDS)
    stopwords.add("没有")
    image = Image.open("shapes/bgpng/" + shapes + ".png")
    graph = np.array(image)
    wc = WordCloud(font_path=fp, background_color='white', max_words=500,
                   mask=graph, stopwords=stopwords)
    wc.generate_from_frequencies(keywords)
    image_color = ImageColorGenerator(graph)
    # fig=plt.figure(figsize=(12,7))
    wc.recolor(color_func=image_color)
    wc.to_file("result/" + shapes + ".png")
    '''    plt.imshow(wc)
    plt.axis("off")'''
    # 合并加背景
    bg = Image.open("shapes/bgpng/" + shapes + ".png").convert('RGBA')
    im = Image.open("result/" + shapes + ".png").convert('RGBA')
    img = Image.blend(im, bg, 0.1)
    img.save("result/" + shapes + "1.png")
    # plt.savefig("result/"+shapes+".png")
    plt.imshow(img)
    plt.show()


if __name__ == '__main__':
    file_txt = 'txt/道德经.txt'
    shapes = 'camel'
    fp = "font/华康海报体W12.ttf"
    song(file_txt, shapes, fp)
