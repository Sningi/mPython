# -*- coding: utf-8 -*-
import os
from PIL import Image, ImageFont, ImageDraw


def get_files(dir_path, file_list):
    '''递归遍历文件文件夹，获得局对路径'''
    files = os.listdir(dir_path)
    for file in files:
        path = os.path.join(dir_path, file)
        if os.path.isdir(path):
            get_files(path, file_list)
        else:
            file_list.append(path)


def font_to_img(text, fontpath, fontsize, color='#EBCCCC', size=(400, 250), background=(255, 255, 255)):
    img = Image.new("RGB", size, background)
    dr = ImageDraw.Draw(img)
    font = ImageFont.truetype(fontpath, fontsize)
    dr.text((50, 50), text, font=font, fill=color)
    return img


def font_to_img_test():
    img = font_to_img('寧', '/home/sning/myfile/font/hksn.ttf',
                      100, '#EBCCCC', (250, 250), (255, 255, 255))
    img.show()


def get_files_test():
    filelist = []
    get_files('/home/sning/myfile/mpython', filelist)
    for i in filelist:
        print(i)


if __name__ == '__main__':
    # get_files_test()
    font_to_img_test()
