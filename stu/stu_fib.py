fibs=[0,1]
print(fibs[-2],fibs[-1],'\n')
num=int(input("input num:"))
for i in range(num-1):
    fibs.append(fibs[-2]+fibs[-1])
print(fibs)
