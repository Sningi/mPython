from turtle import *
from time import sleep
screensize(800,600, "pink")

def go_to(x, y):
    up()
    goto(x, y)
    down()


def big_Circle(size):  # 函数用于绘制心的大圆
    speed(10)
    for i in range(150):
        forward(size)
        right(0.3)


def small_Circle(size):  # 函数用于绘制心的小圆
    speed(10)
    for i in range(210):
        forward(size)
        right(0.786)


def line(size):
    speed(1)
    forward(51*size)


def heart(x, y, size):
    go_to(x, y)
    left(150)
    begin_fill()
    line(size)
    big_Circle(size)
    small_Circle(size)
    left(120)
    small_Circle(size)
    big_Circle(size)
    line(size)
    end_fill()


def arrow():
    pensize(5)
    setheading(0)
    go_to(-400, 0)
    left(15)
    forward(150)
    go_to(339, 178)
    forward(150)


def arrowHead():
    forward(10)
    pensize(1)
    speed(5)
    color('red')
    begin_fill()
    left(120)
    forward(10)
    right(150)
    forward(10*3**0.5)
    right(120)
    forward(10*3**0.5)
    right(150)
    forward(10)
    end_fill()


def love():
    pensize(2)
    setup(1200, 800)
    color('red')
    speed(20)
    # getscreen().tracer(30, 0) #取消注释后，快速显示图案
    heart(200, 0, 1)  # 画出第一颗心，前面两个参数控制心的位置，函数最后一个参数可控制心的大小
    setheading(0)  # 使画笔的方向朝向x轴正方向
    heart(-80, -100, 1.5)  # 画出第二颗心
    arrow()  # 画出穿过两颗心的直线
    arrowHead()  # 画出箭的箭头
    go_to(200, -200)
    write("author：song", move=True, align="left", font=("宋体", 30, "normal"))
    done()


"""
plist is list of pens.
l is length of branch.
a is half of the angle between 2 branches.
f is factor by which branch is shortened from level to level.
"""


def drawTree(plist, l, a, f):
    if l > 5:
        lst = []
        for p in plist:
            p.forward(l)    # 沿着当前的方向画画
            # Move the turtle forward by the specified distance,
            # in the direction the turtle is headed.
            q = p.clone()   # Create and  return a clone of the turtle with
            # same position, heading and turtle properties.
            p.left(a)       # Turn turtle left by angle units.
            q.right(a)      # Turn turtle right by angle units, nits are by
            # default degrees, but can be set via the degrees()
            # and radians() functions.
            lst.append(p)   # 将元素增加到列表的最后
            lst.append(q)
        drawTree(lst, l * f, a, f)


def makeTree(x, y):
    p = Turtle()
    p.color("green")
    p.pensize(5)
    # p.setundobuffer(None)
    p.hideturtle()          # Make the turtle invisible. It's a good idea to do
    # this while you're in the middle of doing some
    # complex drawing because hiding the turtle speeds
    # up the drawing observabley.
    p.speed(20)
    # p.getscreen().tracer(30, 0) # Return the TurtleScreen object the turtle is
    # drawing on. TurlteScreen methods can then be
    # called for that object.
    # turtle帮助说明：http://freecode.com/projects/pythontracer
    # 个人理解就是使程序尽快的执行。
    p.left(90)

    p.penup()
    p.goto(x, y)
    p.pendown()

    t = drawTree([p], 200, 65, 0.6375)
    print(len(p.getscreen().turtles()))  # 用了多少个turtle绘制


def tree():
    #makeTree(-200, -200)
    makeTree(0, -200)


def HSB2RGB(hues):
    hues = hues * 3.59 #100转成359范围
    rgb=[0.0,0.0,0.0]
    i = int(hues/60)%6
    f = hues/60 -i
    if i == 0:
        rgb[0] = 1; rgb[1] = f; rgb[2] = 0
    elif i == 1:
        rgb[0] = 1-f; rgb[1] = 1; rgb[2] = 0
    elif i == 2:
        rgb[0] = 0; rgb[1] = 1; rgb[2] = f
    elif i == 3:
        rgb[0] = 0; rgb[1] = 1-f; rgb[2] = 1
    elif i == 4:
        rgb[0] = f; rgb[1] = 0; rgb[2] = 1
    elif i == 5:
        rgb[0] = 1; rgb[1] = 0; rgb[2] = 1-f
    return rgb
     
def rainbow():
    hues = 0.0
    color(1,0,0)
    #绘制彩虹
    hideturtle()
    #隐藏乌龟
    speed(5)
    pensize(3)
    penup()
    goto(-650,-150)
    pendown()
    right(110)
    for i in range (100):
        circle(600)
        #圆的半径600
        right(0.23)
        hues = hues + 1
        rgb = HSB2RGB(hues)
        color(rgb[0],rgb[1],rgb[2])    
    penup()
     
def hong():
    setup(1200, 800, 0, 0)
    bgcolor((64/255, 64/255, 1))
    tracer(False)
    rainbow()
    #输出文字
    tracer(False)
    goto(0,0)
    pendown()
    color('yellow')
    write("彩虹",align="center",
          font=("Script MT Bold", 80, "bold"))
    tracer(True)
    done()

tracer(2)
#hong()
love()
#tree()