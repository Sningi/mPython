# class ani:
#     def islive(bo):
#         if bo:
#             return True
#         else:
#             return False


# class Person(ani):
#     # super(Person, self)

#     def setName(self, name):
#         self.name = name

#     def getName(self):
#         return self.name

#     def greet(self):
#         print('hello,I am %s.' % self.name)


# # while True:
# #     com = input("com:\n")
# #     if not com:
# #         break
# #     exec(com)

# if __name__ == '__main__':
#     # p=Person()
#     # print(dir())
#     items=['3','t','','i']
#     data=(item for item in items if item)
#     g=globals()
#     # print(g)
#     print( format(10, '#o'), format(10, ''),5**5)
#     import itertools
#     a= itertools.zip_longest('124','56789')
#     # print(a)
#     for i in a :
#         print(i)
#     # print(str(Ellipsis))
#     # print()
#     # quit()
#     # exit()
#     print(copyright,credits,license,"hello")
# import turtle
# import random
# turtle.tracer(0, 0)
# mi = turtle.Screen()
# mi.colormode(255)
# turtle.bgcolor("black")
# alex = turtle.Turtle()
# alex.speed(10)
# alex.goto(0,0)
# alex.pensize(0)
# alex.ht()
# for i in range(500):
#     alex.color(random.randrange(256),random.randrange(256),random.randrange(256))
#     alex.goto(round(random.gauss(0,150),0),round(random.gauss(0,150),0))
#     x = alex.xcor()
#     y = alex.ycor()
#     for j in range(25):
#                 z = round(random.gauss(0,5), 0)
#                 a = round(random.gauss(0,5), 0)
#                 alex.color(random.randrange(256),random.randrange(256),random.randrange(256))
#                 alex.pensize(0)
#                 alex.goto(x + z, y + a)
#     alex.goto(z,a)
# turtle.update()
# mi.exitonclick()
# import random
# import turtle
# def colorGen(sat = 1, val = 1):
#     rand1 = round(random.randrange(256)*val)
#     rand2 = round(random.randrange(256)*val)
#     sat2 = round((1-sat)*255)
#     if rand1 >= rand2:
#         rand1 = round(255*val)
#     else:
#         rand2 = round(255*val)
#     color = [[sat2, rand1, rand2], [rand1, sat2, rand2], [sat2, rand2, rand1],
#             [rand1, rand2, sat2], [rand2, sat2, rand1], [rand2, rand1, sat2]]
#     return tuple(color[random.randrange(6)])
# def timeTunnel(repeats = 1,linuxmi = 10, stepVar = 1):
#     for i in range(repeats):
#         alex.goto(0,0)
#         alex.seth(random.uniform(0,360)) # 设定标题
#         h1 = alex.heading() # 设定标题
#         alex.color(colorGen(val=0))
#         for j in range(10):
#             alex.down()
#             alex.forward(abs(round(random.gauss(10, stepVar),0))) 
#             alex.seth(h1 + random.gauss(0,linuxmi))
#             x = alex.xcor()
#             y = alex.ycor()
#             alex.color(colorGen(val = j/10))
#             f2 = alex.heading()
#         for k in range(3):
#             alex.down()
#             alex.seth(f2 + random.gauss(0, linuxmi))
#             h3 = alex.heading()
#             for u2 in range(10):
#                 alex.color(colorGen(val = u2/10))
#                 alex.seth(h3 + random.gauss(0,linuxmi))
#                 alex.forward(abs(round(random.gauss(10, stepVar), 0)))
#             m = alex.xcor()
#             n = alex.ycor()
#             h4 = alex.heading()
#             for l in range(2):
#                 alex.color(colorGen())
#                 alex.down()
#                 alex.seth(abs(h4 + random.gauss(0,linuxmi)))
#                 h5 = alex.heading()
#                 for l2 in range(10):
#                     alex.color(colorGen(val = l2/10))
#                     alex.seth(h5 + random.gauss(0,linuxmi))
#                     alex.forward(abs(round(random.gauss(10,stepVar),0)))
#                 alex.up()
#             alex.goto(x, y)
#         alex.up()
# turtle.tracer(0, 0)
# wn = turtle.Screen()
# wn.colormode(255)
# turtle.bgcolor("black")
# alex = turtle.Turtle()
# alex.speed(10)
# alex.pensize(0)
# alex.ht()
# timeTunnel(300)
# turtle.update()
# wn.exitonclick()

if 123456789 is 123456789:
    print("k")
print(id(123456789),id(123456789))
print(id(123456789),id(123456789))
print(divmod(5,0))