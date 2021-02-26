#!/usr/bin/python
import turtle
turtle.setup(800,350,400,300)
turtle.penup()
turtle.fd(-350)
turtle.pendown()
turtle.pensize(25)
turtle.pencolor("purple")
turtle.seth(-40)
for i in range(4):
    turtle.circle(40,80)
    turtle.circle(-80,80)
turtle.circle(40,40)
turtle.fd(40)
turtle.circle(16,180)
turtle.fd(40*2/3)
turtle.done()