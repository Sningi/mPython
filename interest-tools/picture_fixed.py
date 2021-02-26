#磨皮算法Dest=(Src*(100-Opacity)+(Src+2*GuassianBlur(EPFFilter(Src)-Src+128)-256)
#*Opacity)/100
import cv2
import numpy as np

def beauty_face(img,Op):
    dst = np.zeros_like(img)
    #int value1 = 3,value2 = 1;磨皮程度与细节程度
    value1 = 3
    value2 = 1
    dx = value1 * 12 #双边滤波参数一
    fc = value1 * 8 #双边滤波参数二
    p = Op #图片融合比例(透明度)
    temp4 = np.zeros_like(img)
    temp1 = cv2.bilateralFilter(img,dx,fc*2,fc/2) #双边滤波EPFFilter(Src)
    temp2 = cv2.subtract(temp1,img) #EPFFilter(Src)-Src
    temp2 = cv2.add(temp2,(10,10,10,128)) #EPFFilter(Src)-Src+128
    temp3 = cv2.GaussianBlur(temp2,(2*value2 - 1, 2*value2 -1),0,0) #高斯模糊
    temp3 = 2*temp3 #2*GuassianBlur
    temp4 = cv2.add(img,temp3)#Src+2*GuassianBlur
    dst = cv2.addWeighted(img,p,temp4,1-p,0.0)
    dst = cv2.add(dst,(10,10,10,255))
    return dst

path = input("输入图片路径:")
img = cv2.imread(str(path)) #读图片
p = float(input("输入磨皮程度(0-1):"))
p = 1 - p
dst = beauty_face(img,p) #调用函数进行磨皮处理
is_show = input("是否显示对比图(1:是,2:否)(显示图片后按任意键关闭图片):")
if (int(is_show) == 1):    
    cv2.imshow("SRC",img) #显示原图像
    cv2.imshow("DST",dst) #显示磨皮后图像
    cv2.waitKey(0)
    cv2.destroyAllWindows()
is_save = input("是否保存图片(1:是,2:否):")
if (int(is_save) == 1):
    path = input("输入保存地址:")
    cv2.imwrite(str(path),dst)
