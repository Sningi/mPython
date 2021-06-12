import turtle
turtle.setup(500, 600)
# turtle.tracer(10)
import time
time.sleep(3)
t = turtle.Pen()
t.pensize(1)
# t.up()
t.goto(0, -150)
# t.down()
t.seth(0)
t.begin_fill()


# blue&white face

t.circle(200)
t.fillcolor("deepskyblue")
t.end_fill()

t.begin_fill()
t.fillcolor("white")

t.circle(160)
t.end_fill()


# nose
t.up()
t.goto(0, -70)
t.down()

t.goto(0, 50)

t.begin_fill()
t.fillcolor("orangered")
t.circle(25)
t.end_fill()

t.up()
t.goto(0, 80)
t.down()
t.begin_fill()
t.fillcolor("white")
t.circle(5)
t.end_fill()

# eye
t.up()
t.goto(-45, 100)
t.down()
t.begin_fill()
t.fillcolor("white")
t.circle(45)
t.end_fill()

t.up()
t.goto(-25, 125)
t.down()
t.begin_fill()
t.fillcolor("black")
t.circle(15)
t.end_fill()

t.up()
t.goto(-20, 133)
t.down()
t.begin_fill()
t.fillcolor("white")
t.circle(7)
t.end_fill()


t.up()
t.goto(45, 100)
t.down()
t.begin_fill()
t.fillcolor("white")
t.circle(45)
t.end_fill()

t.up()
t.goto(25, 125)
t.down()
t.begin_fill()
t.fillcolor("black")
t.circle(15)
t.end_fill()

t.up()
t.goto(20, 133)
t.down()
t.begin_fill()
t.fillcolor("white")
t.circle(7)
t.end_fill()

# smile
t.up()
t.goto(0, -70)
t.down()

t.circle(150, extent=-65)

t.circle(150, extent=65)

t.circle(150, extent=65)

t.circle(150, extent=-65)
# 胡子右
t.up()
t.goto(50, 40)
t.down()
t.seth(12)
t.fd(130)

t.up()
t.goto(50, 30)
t.down()
t.seth(0)
t.fd(130)

t.up()
t.goto(50, 20)
t.down()
t.seth(-12)
t.fd(130)

# 胡子左
t.up()
t.goto(-50, 40)
t.down()
t.seth(-12)
t.fd(-130)

t.up()
t.goto(-50, 30)
t.down()
t.seth(0)
t.fd(-130)

t.up()
t.goto(-50, 20)
t.down()
t.seth(12)
t.fd(-130)

# 舌头
t.up()
t.goto(0, -70)
t.seth(0)
t.circle(150, extent=40)
t.down()

t.begin_fill()
t.seth(135)
t.fillcolor("orangered")
t.circle(-60, extent=20)
t.circle(-40, extent=20)
t.seth(90)
t.circle(-20, extent=120)
t.circle(-60, extent=20)
t.circle(-40, extent=2)
t.seth(56)
t.circle(150, extent=-15)
t.end_fill()
t.circle(150, extent=6)
t.seth(135)
t.color('firebrick')
t.circle(-200, extent=8)
t.up()
t.goto(-200, -200)
t.down()
turtle.done()
