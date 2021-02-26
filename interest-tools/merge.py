from PIL import Image
import os
import sys
mw = 426  # 每张图大小：长度
# 若不想设置成正方形 #例如：wh=300
ms = 3  # 列数。每行几张图
msize = mw * ms
toImage = Image.new('RGB', (1200, 1200))  # 画布大小

for y in range(1, 4):
    for x in range(1, 4):
        try:
            fromImage = Image.open(r"%s.jpg" %
                                   str(ms * (y - 1) + x))
            fromImage = fromImage.resize((400, 400), Image.ANTIALIAS)
            toImage.paste(fromImage, ((x - 1) * mw, (y - 1) * mw))
        except IOError:
            pass

if __name__ == '__main__':
    toImage.show()
   # toImage = toImage.convert('RGB')
   # toImage = toImage.save('jingangjing.png')
