# #!/usr/bin/env python
# from PIL import Image, ImageDraw, ImageFont, ImageFilter
# from pylab import mpl

# mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 指定默认字体


# def insert_text(text, fone_type_file, font_size, im, position):
#     '''
#     ** text 要插入的文字
#     ** fone_type_file 文字类型文件名称
#     ** font_size 文字大小
#     ** im 背景图片
#     ** position 要插入的位置
#     '''

#     datas = text.split('\n')
#     data = ''
#     if not datas:
#         datas = [text]
#     for d in datas:
#         if not d:
#             d = ' '
#         elif len(d) > 31:
#             d1 = d[:30] + '\n'
#             d2 = d[30:]
#             d = d1 + ' \n' + d2
#         data += (d + '\n')
#         data += ' \n'

#     data = data[:-1]
#     dr = ImageDraw.Draw(im)
#     font = ImageFont.truetype(fone_type_file, font_size)

#     dr.text(position, data, font=font, fill="#000000", spacing=0, align='left')
#     im.save("t.png")
#     return im, len(datas)


# def main():
#     text = "11月3号,晴天"
#     insert_text()

# -*- coding:utf-8 -*-

from PIL import Image, ImageDraw, ImageFont


def insert_text(img, text):
    # text="        "+text
    datas = text.split('\n')
    data = ''
    if not datas:
        print("helej")
        datas = [text]
    for d in datas:
        print(len(d))
        if not d:
            print("kongg")
            d = ' '
        elif 24 > len(d) > 12:
            print("dhjh")
            d1 = d[:12]  # + '\n'
            d2 = d[12:]
            d = d1 + '\n' + d2
        elif len(d) > 23:
            print("24")
            d1 = d[:12]
            d2 = d[14:26]
            d3 = d[26:]
            d = d1 + "\n" + d2 + '\n' + d3
        data = d

    # data = data[:-1]
    data = "        " + data
    sy = "/usr/share/fonts/adobe-source-han-serif/SourceHanSerifCN-SemiBold.otf"
    w5 = '/home/sning/PycharmProjects/pic/w5.TTF'
    setFont = ImageFont.truetype(
        sy, 20)
    fillColor = "#000000"
    image = Image.open(img)
    draw = ImageDraw.Draw(image)
    width, height = image.size
    position = (10, 230)  # (40, height - 100)
    draw.text(position, data, font=setFont, fill=fillColor, align="left")
    image.show(),
    image.save("pic/mg.jpg", 'jpeg')

    return 0


if __name__ == '__main__':
    img = 'pic/timg.jpg'
    text = u"不断地明悟道理，不断地忘记教训    过犹不及"
    # text = u"该字符串共有11个字符，其中有7个汉字，4个英文，0个空格，0个数字，0 个标点符号"
    insert_text(img, text)
