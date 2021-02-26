import turtle
import random
import time

cl = ['yellow', 'red', 'purple', 'green', 'blue', 'orange', 'black']


def drawLine(draw):  # 绘制单段数码管
    turtle.pencolor(random.choice(cl))
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(40)
    turtle.right(90)


def drawDigit(digit):  # 根据数字绘制七段数码管
    drawLine(True) if digit in [2, 3, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 1, 3, 4, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 3, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 6, 8] else drawLine(False)
    turtle.left(90)
    drawLine(True) if digit in [0, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 3, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 1, 2, 3, 4, 7, 8, 9] else drawLine(False)
    turtle.left(180)
    turtle.penup()  # 为绘制后续数字确定位置
    turtle.fd(20)  # 为绘制后续数字确定位置


def drawDate(date):  # 获得要输出的数字
    for i in date:
        drawDigit(eval(i))  # 通过eval()函数将数字变为整数


def main():
    turtle.setup(800, 350, 200, 200)
    turtle.penup()
    turtle.fd(-300)
    turtle.pensize(8)
    turtle.speed(10)
    turtle.pencolor(random.choice(cl))
    ltime = time.localtime()
    strt = str(ltime.tm_year)+str(ltime.tm_mon)+str(ltime.tm_mday)
    #print(strt)
    drawDate(strt)
    turtle.hideturtle()
    turtle.done()


main()
