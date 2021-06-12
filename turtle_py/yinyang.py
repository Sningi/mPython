from turtle import *
def yin(radius, color1, color2):
    width(3)
    color("pink", color1)
    begin_fill()
    circle(radius/2., 180)
    circle(radius, 180)
    left(180)
    circle(-radius/2., 180)
    end_fill()
    left(90)
    up()
    forward(radius*0.35)
    right(90)
    down()
    color(color1, color2)
    begin_fill()
    circle(radius*0.15)
    end_fill()
    left(90)
    up()
    backward(radius*0.35)
    down()
    left(90)


def yinyang():
    reset()
    yin(200, "red", "white")
    yin(200, "blue", "black")
    done()
    return "Done!"

yinyang()