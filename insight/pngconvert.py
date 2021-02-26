from PIL import Image
import os


def f1():
    # 转换 索引图像PNG->RGB图像
    path = "shapes/pn/"
    for filename in os.listdir(path):
        if os.path.splitext(filename)[1] == '.png':
            im = Image.open(path + filename)
            im.convert("RGBA").save("shapes/RGBpng/" + filename)


def f2():
    # 为PNG填充背景色
    path = "shapes/bgpng/fruiticons_buttons/"
    for filename in os.listdir(path):
        if os.path.splitext(filename)[1] == '.png':
            im = Image.open(path + filename)
            x, y = im.size
            # 使用白色来填充背景 from：www.outofmemory.cn
            p = Image.new('RGBA', im.size, (255, 255, 255))
            p.paste(im, (0, 0, x, y), im)
            # p.show()
            p.save("shapes/bgpng/fruiticons_buttons/song_" + filename)


def f3(shapes):
    bg = Image.open("shapes/bgpng/" + shapes + ".png").convert('RGBA')
    im = Image.open("shapes/result/" + shapes + ".png").convert('RGBA')
    img = Image.blend(im, bg, 0.1)
    img.save("shapes/result/" + shapes + "1.png")


im = Image.open('5.png')
x, y = im.size
# 使用白色来填充背景 from：www.outofmemory.cn
p = Image.new('RGBA', im.size, (255, 255, 255))
p.paste(im, (0, 0, x, y), im)
# p.show()
p.save("5.png")
