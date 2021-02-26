import turtle
t = turtle.Pen()
turtle.bgcolor("black")
# sides=eval(input("输入要绘制的边的数目，请输入2-6的数字！"))
sides = 6
colors = ["red", "yellow", "green", "blue", "orange", "purple"]
turtle.tracer(1.5)
for x in range(360):
    t.pencolor(colors[x % sides])
    t.forward(x * 3 / sides + x)
    t.left(360 / sides + 1)
    t.width(x * sides / 180)
    t.left(91)
turtle.done()
