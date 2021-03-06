import turtle as t
# import tkinter as tk
base = (14, -70)


def body():
    t.penup()
    t.goto(base)
    t.pensize(1.4)
    t.pendown()
    t.fillcolor('turquoise')  # lightseagreen
    t.begin_fill()
    t.seth(-25)
    t.circle(-6, 110)
    t.seth(28)
    t.circle(200, 19)
    t.circle(200, -1)
    t.seth(-90)
    # 后脚
    t.circle(100, 6)
    print(t.position(), t.heading())
    t.circle(5, 180)
    t.right(28)
    t.circle(150, 37)
    t.left(40)
    t.circle(150, 23)
    t.left(15)
    t.circle(240, 29)
    t.left(47)
    t.circle(150, 38)
    t.left(37)
    print("左前：", t.position(), t.heading())
    t.circle(200, 21)
    t.right(80)
    # 右前脚
    t.circle(100, -1)
    t.circle(100, 10)
    t.right(110)
    t.circle(6, 160)
    h = t.heading()
    t.seth(85)
    t.fd(5)
    t.bk(5)
    t.seth(h)
    t.circle(6, 30)
    h = t.heading()
    t.seth(85)
    t.fd(6)
    t.bk(6)
    t.seth(h)
    t.right(20)
    t.circle(10, 30)
    t.circle(20, 40)
    t.left(30)
    t.circle(200, 9)
    t.goto(base)
    t.end_fill()


def leg(p, h):
    t.penup()
    t.goto(p)
    t.seth(h)
    t.circle(200, 1)
    end = t.position()
    t.pensize(1.4)
    t.pendown()
    t.fillcolor('turquoise')  # lightseagreen
    t.begin_fill()
    t.right(55)
    t.circle(50, 20)
    t.right(120)
    t.circle(6, 155)

    h = t.heading()
    t.seth(85)
    t.fd(7)
    t.bk(7)
    t.seth(h)
    t.circle(6, 40)
    h = t.heading()
    t.seth(85)
    t.fd(6)
    t.bk(6)
    t.seth(h)
    t.right(20)
    t.circle(10, 35)
    t.circle(20, 28)
    t.left(35)
    t.circle(200, 3.5)
    t.seth(155)
    t.circle(200, 7)
    t.goto(end)
    t.end_fill()


def eye1():
    t.penup()
    t.goto(-70, 0)
    t.pendown()
    t.fillcolor('white')
    t.begin_fill()
    t.seth(90)
    t.circle(15, 50)
    t.right(20)
    t.circle(15, 40)
    t.right(20)
    t.circle(20, 50)
    t.right(20)
    t.circle(15, 40)
    t.right(15)
    t.circle(15, 50)
    t.right(13)
    t.circle(20, 30)
    t.left(10)
    t.circle(20, 40)
    t.right(5)
    t.circle(20, 30)
    t.right(15)
    t.circle(25, 40)
    t.right(15)
    t.circle(15, 50)
    t.right(15)
    t.circle(15, 50)
    t.right(15)
    t.circle(15, 50)
    t.right(15)
    t.circle(15, 50)
    t.goto(-70, 0)
    t.end_fill()


def eye1w():
    p = -110, 12
    t.penup()
    t.goto(p)
    t.seth(142)
    t.pendown()
    t.fillcolor('white')
    t.begin_fill()
    t.circle(3.5, 360)
    t.goto(p)
    t.end_fill()


def eye1black():
    t.penup()
    p = -120, 11
    t.goto(p)
    t.seth(-130)
    t.pendown()
    t.fillcolor('dimgray')
    t.begin_fill()
    t.circle(12, 360)
    t.goto(p)
    t.end_fill()


def eye2():
    p = 40, -17
    t.penup()
    t.goto(p)
    t.pendown()
    t.fillcolor('white')
    t.begin_fill()
    t.seth(95)
    t.circle(15, 50)
    t.right(20)
    t.circle(15, 40)
    t.right(20)
    t.circle(20, 50)
    t.right(30)
    t.circle(15, 40)
    t.right(20)
    t.circle(15, 50)
    t.right(20)
    t.circle(20, 30)
    t.right(5)
    t.circle(20, 25)
    t.right(5)
    t.circle(20, 30)
    t.circle(25, 40)
    t.right(3)
    t.circle(20, 40)
    t.right(15)
    t.circle(30, 50)
    t.right(20)
    t.circle(15, 50)
    t.right(20)
    t.circle(20, 50)
    t.left(10)
    t.circle(15, 20)
    t.goto(p)
    t.end_fill()


def eye2black():
    t.penup()
    p = 37, -15
    t.goto(p)
    t.seth(100)
    t.pendown()
    t.fillcolor('dimgray')
    t.begin_fill()
    t.circle(13.5, 360)
    t.goto(p)
    t.end_fill()


def eye2w():
    p = 30, -9
    t.penup()
    t.goto(p)
    t.pendown()
    t.fillcolor('white')
    t.begin_fill()
    t.circle(3.5, 360)
    t.goto(p)
    t.end_fill()


def eye():
    eye1()
    eye1black()
    eye1w()
    eye2()
    eye2black()
    eye2w()


def jiaya():
    p = 66.23, -52.48
    t.penup()
    t.goto(p)
    t.seth(276)
    t.pendown()
    t.fillcolor('burlywood')
    t.begin_fill()
    t.circle(5, 180)
    t.right(30)
    t.fd(3)
    t.right(90)
    t.fd(3)
    t.seth(-105)
    t.circle(-50, 32)
    t.right(110)
    t.circle(15, 20)
    t.left(60)
    t.circle(15, 30)
    t.right(120)
    t.circle(15, 30)
    t.left(50)
    t.circle(15, 21)
    t.right(120)
    t.circle(-8, 60)
    t.circle(50, 15)
    t.goto(p)
    t.end_fill()


def zuiba():
    p = -50, -14
    t.penup()
    t.goto(p)
    t.left(180)
    t.pendown()
    t.begin_fill()
    t.circle(30, 50)
    t.right(92)
    t.circle(60, -9)
    t.circle(60, 37)
    t.left(5)
    t.circle(30, 30)
    t.seth(-50)
    t.circle(30, 30)
    t.left(5)
    t.circle(60, 15)
    t.left(15)
    t.circle(60, 18)
    t.circle(-60, 17)
    t.circle(-60, -17)
    t.seth(-9)
    t.circle(60, 32)
    t.seth(140)
    t.circle(-60, 30)
    t.left(10)
    t.circle(-60, 15)
    t.goto(p)
    t.end_fill()


def daimao():
    p = -36, 35
    t.penup()
    t.goto(p)
    t.pensize(2)
    t.pendown()
    t.left(30)
    t.circle(50, 24.5)
    t.seth(-70)
    t.circle(50, 10)
    t.seth(-170)
    t.circle(50, 16)
    t.seth(-15)
    t.circle(50, 16)
    t.seth(-145)
    t.circle(50, 16)
    t.seth(10)
    t.circle(50, 16)
    t.goto(p)


if __name__ == '__main__':
    # t.tracer(10)
    t.screensize(500, 350, "pink")  # limegreen
    t.setup(640, 361, 0, 400)
    t.speed(10)
    # t.hideturtle()
    t.pen(5)
    # t.bgpic('ti.png')
    t.pencolor('dimgray')
    import time
    time.sleep(2)
    body()
    leg((-73.89, -65.43), 334)
    eye()
    jiaya()
    zuiba()
    daimao()
    # t.home()
    t.done()
    # import time
    # time.sleep(3)
